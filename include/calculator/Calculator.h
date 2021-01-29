//
// Created by maciej on 28.01.2021.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>

#define DEFAULT_PRECISION 6


class CalcTypeless {
public:
    virtual std::string getResult(std::string arg) = 0;
};

template<typename number>
class Calculator : public CalcTypeless {

public:
    explicit Calculator();

    std::string getResult(std::string arg) override;
    void setPrecision(int precision);
    ~Calculator();

private:
    int precision = DEFAULT_PRECISION;

    number calculate(std::string arg);
    std::string replaceAll(std::string source, std::string toReplace, std::string replacement);
    size_t findClosingBracket(std::string& source, size_t openingPosition);

};

template class Calculator<long>;
template class Calculator<float>;
template class Calculator<int>;
template class Calculator<double>;

#endif //CALCULATOR_CALCULATOR_H
