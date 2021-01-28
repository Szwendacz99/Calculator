//
// Created by maciej on 28.01.2021.
//

#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <calculator.h>

using namespace std;

template<typename type>
type Calculator<type>::calculate(string arg) {
    if (arg.find("--") != string::npos)
        arg = replaceAll(arg, "--", "");

    cout << "##### " << arg << endl;
    if (arg.find('(') != string::npos) {
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
    } else if (arg.find('-') != string::npos && arg.find('-') != 0 && arg[arg.find('-') - 1] != '^') {
        return calculate(arg.substr(0, arg.find('-'))) -
               calculate(arg.substr(arg.find('-') + 1));
    } else if (arg.find('*') != string::npos) {
        return calculate(arg.substr(0, arg.find('*'))) *
               calculate(arg.substr(arg.find('*') + 1));
    } else if (arg.find('/') != string::npos) {
        return calculate(arg.substr(0, arg.find('/'))) /
               calculate(arg.substr(arg.find('/') + 1));
    } else if (arg.find('^') != string::npos) {
        return pow(calculate(arg.substr(0, arg.find('^'))) ,
                   calculate(arg.substr(arg.find('^') + 1)));
    }

    return (type) stod(arg);
}

template<typename type>
Calculator<type>::Calculator(int precision): precision(precision){

}

template<typename type>
string Calculator<type>::replaceAll(string source, string toReplace, string replacement) {
    if (toReplace.empty()) {
        throw "Bad arguments to replace !";
    }

    while(source.find(toReplace) != string::npos)
    {
        source.replace(source.find(toReplace), (size_t) toReplace.size(), replacement);
    }
    return source;
}

template<typename type>
size_t Calculator<type>::findClosingBracket(string& source, size_t openingPosition) {
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

template<typename type>
string Calculator<type>::getResult(string arg) {
    arg = replaceAll(arg," ", "");
    std::stringstream stream;
    stream << setprecision(precision) << calculate(arg);
    return stream.str();
}

template<typename type>
Calculator<type>::~Calculator() {
    std::cout << "Calculator object is destroyed!" << std::endl;
}

