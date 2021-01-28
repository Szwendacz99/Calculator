//
// Created by maciej on 28.01.2021.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>


class CalcTypeless {
public:
    virtual std::string getResult(std::string arg) = 0;
};

template<typename type>
class Calculator : public CalcTypeless {

public:
    Calculator(int precision);

    std::string getResult(std::string arg);
    ~Calculator();

private:
    int precision;

    type calculate(std::string arg);
    std::string replaceAll(std::string source, std::string toReplace, std::string replacement);
    size_t findClosingBracket(std::string& source, size_t openingPosition);

};

template class Calculator<long>;
template class Calculator<float>;
template class Calculator<int>;
template class Calculator<double>;

#endif //CALCULATOR_CALCULATOR_H
