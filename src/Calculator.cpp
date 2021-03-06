//
// Created by maciej on 28.01.2021.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <Calculator.h>
#include <QtDebug>


using namespace std;

template<typename number>
number Calculator<number>::calculate(string arg) {
    if (arg.find("--") != string::npos)
        arg = replaceAll(arg, "--", "");

//    cout << "##### " << arg << endl;
    if (arg.find("sin(") != string::npos) {
        size_t positionStart = arg.find("sin(");
        size_t positionEnd = findClosingBracket(arg, positionStart+3);
        if (positionEnd == string::npos) {
            throw "missing closing brackets!";
        }
        return calculate(replaceAll(arg, arg.substr(positionStart, positionEnd - positionStart + 1),
                                    to_string(sin(calculate(arg.substr(positionStart+3 ,
                                                                       positionEnd - positionStart -2))))));
    }else if (arg.find("cos(") != string::npos) {
        size_t positionStart = arg.find("cos(");
        size_t positionEnd = findClosingBracket(arg, positionStart+3);
        if (positionEnd == string::npos) {
            throw "missing closing brackets!";
        }
        return calculate(replaceAll(arg, arg.substr(positionStart, positionEnd - positionStart + 1),
                                    to_string(cos(calculate(arg.substr(positionStart+3 ,
                                                                       positionEnd - positionStart -2))))));
    }else if (arg.find("tan(") != string::npos) {
        size_t positionStart = arg.find("tan(");
        size_t positionEnd = findClosingBracket(arg, positionStart+3);
        if (positionEnd == string::npos) {
            throw "missing closing brackets!";
        }
        return calculate(replaceAll(arg, arg.substr(positionStart, positionEnd - positionStart + 1),
                                    to_string(tan(calculate(arg.substr(positionStart+3 ,
                                                                   positionEnd - positionStart -2))))));
    }else if (arg.find('(') != string::npos) {
        size_t positionStart = arg.find('(');
        size_t positionEnd = findClosingBracket(arg, positionStart);
        if (positionEnd == string::npos) {
            throw "missing closing brackets!";
        }

        return calculate(replaceAll(arg, arg.substr(positionStart, positionEnd - positionStart + 1),
                                    to_string(calculate(arg.substr(positionStart + 1,
                                                                    positionEnd - positionStart - 1)))));
    } else if (arg.find('+') != string::npos) {
        return calculate(arg.substr(0, arg.find('+'))) +
               calculate(arg.substr(arg.find('+') + 1));
    } else if (arg.find('-') != string::npos && arg.find('-') != 0 && arg[arg.find('-') - 1] != '^'
                                                                      && arg[arg.find('-') - 1] != '*'
                                                                         && arg[arg.find('-') - 1] != '/') {
        return calculate(arg.substr(0, arg.find('-'))) -
               calculate(arg.substr(arg.find('-') + 1));
    } else if (arg.find('*') != string::npos) {
        return calculate(arg.substr(0, arg.find('*'))) *
               calculate(arg.substr(arg.find('*') + 1));
    } else if (arg.find_last_of('/') != string::npos) {
        // because of bug with phrases like 1/2/2/2/2 where it splits in wrong order
        // when dividing, there is need of using find_last_of instead of find
        return calculate(arg.substr(0, arg.find_last_of('/'))) /
               calculate(arg.substr(arg.find_last_of('/') + 1));
    } else if (arg.find('^') != string::npos) {
        return pow(calculate(arg.substr(0, arg.find('^'))) ,
                   calculate(arg.substr(arg.find('^') + 1)));
    }

    return (number) stod(arg);
}

template<typename number>
Calculator<number>::Calculator(){
    qDebug() << "Starting Calculator object, type of number: " << typeid(number).name();

}

template<typename number>
string Calculator<number>::replaceAll(string source, string toReplace, string replacement) {
    if (toReplace.empty()) {
        throw "Bad arguments to replace !";
    }

    while(source.find(toReplace) != string::npos)
    {
        source.replace(source.find(toReplace), (size_t) toReplace.size(), replacement);
    }
    return source;
}


template<typename number>
size_t Calculator<number>::findClosingBracket(string& source, size_t openingPosition) {
    int newOpenCount=0;
    for (unsigned long x=openingPosition+1;x<source.size();x++) {
        if (source[x] == ')') {
            if (newOpenCount==0)
                return x;
            newOpenCount--;
        } else if (source[x] == '(') {
            newOpenCount++;
        }
    }
    return string::npos;
}

template<typename number>
string Calculator<number>::getResult(string arg) {
    arg = replaceAll(arg," ", "");

    // Qt framework messes up locales and because of that std::stod function works with
    // commas instead of dots, then this replacement is needed.
    std::stringstream stream;
    stream << setprecision(precision) << calculate(arg);
    return stream.str();
}

template<typename number>
Calculator<number>::~Calculator() {
    qDebug()<< "Calculator object is destroyed!";
}

template<typename number>
void Calculator<number>::setPrecision(int precision) {
    this->precision = precision;
}

template class Calculator<long>;
template class Calculator<float>;
template class Calculator<int>;
template class Calculator<double>;

