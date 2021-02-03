//
// Created by maciej on 28.01.2021.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include <vector>

#define DEFAULT_PRECISION 6


/**
 * Abstract class for easy use with upcasting of Calculator with different
 * types of variable.
 * Should contain only necessary virtual functions.
 */
class CalcTypeless {
public:
    virtual std::string getResult(std::string arg) = 0;
    virtual void setPrecision(int precision) = 0;
};

/**
 * @tparam number this typename param specifies type of variable to which
 * numbers from string (through double first - string=>double=>properType) will be cast on each operation
 */
template<typename number>
class Calculator : public CalcTypeless {

public:
    explicit Calculator();

    /**
     * Function for returning result of calculations in properly formatted string
     * according to used precision
     * @tparam number
     * @param arg string containing mathematical expression to solve
     * @return string with properly formatted result from successful solving mathematical expression
     */
    std::string getResult(std::string arg) override;

    /**
     * Set precision for calculator object, remember to trigger solving to see
     * result on gui
     * @tparam number
     * @param precision precision of calculations and displayed result. It applies only to float/double type of calculator
     */
    void setPrecision(int precision);
    ~Calculator();

private:
    int precision = DEFAULT_PRECISION;
    /**
     * Recursively calculate result of given mathematical expression
     * If solving fails, method throws char* exceptions, containing cause of error
     * which can be displayed instead of proper result on GUI
     * @tparam number type of variable used in calculations
     * @param arg string containing mathematical expression to solve
     * @return result casted to used number type
     */
    number calculate(std::string arg);

    /**
     * Simply replace all occurrences of phrase to a new one.
     * @tparam number
     * @param source string in which replacing will be done
     * @param toReplace phrase to be found and replaced
     * @param replacement phrase to be put in place(s) of toReplace phrase in source string
     * @return
     */
    std::string replaceAll(std::string source, std::string toReplace, std::string replacement);

    /**
     * Function for finding closing bracket from the specified place which should be opening
     * bracket.
     * @tparam number
     * @param source    reference to string containing brackets
     * @param openingPosition   place from counting of brackets starts until finding of
     * as many closing brackets as opening ones.
     * @return  position of closing bracket for the one specified with position argument
     */
    size_t findClosingBracket(std::string& source, size_t openingPosition);

};


/*
 * templates for possible variable types of calculator
 * to be precompiled and be able to switched to, in runtime.
 */
template class Calculator<long>;
template class Calculator<float>;
template class Calculator<int>;
template class Calculator<double>;

#endif //CALCULATOR_CALCULATOR_H
