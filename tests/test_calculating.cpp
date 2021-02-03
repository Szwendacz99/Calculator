//
// Created by maciej on 03.02.2021.
//

#include <gtest/gtest.h>
#include <Calculator.h>

/**
 * Simple tests for calculations
 */

TEST(Calculations,integerTest) {
    Calculator<int> calc;

    ASSERT_EQ( "0",calc.getResult("1/2"));
    ASSERT_EQ( "10",calc.getResult("1*2+6*6^-2+8"));
    ASSERT_EQ( "246912",calc.getResult("2*123456"));
    ASSERT_EQ( "6",calc.getResult("3.9+3.9"));
    ASSERT_GT( "0",calc.getResult("2*1234567890"));
}

TEST(Calculations,longTest) {
    Calculator<long> calc;

    ASSERT_EQ( "0",calc.getResult("1/2"));
    ASSERT_EQ( "10",calc.getResult("1*2+6*6^-2+8"));
    ASSERT_EQ( "246912",calc.getResult("2*123456"));
    ASSERT_EQ( "6",calc.getResult("3.9+3.9"));
    ASSERT_EQ( "2469135780",calc.getResult("2*1234567890"));
    ASSERT_GT( "0",calc.getResult("53540000*901234567892"));

}

TEST(Calculations,floatTest) {
    Calculator<float> calc;

    calc.setPrecision(10);
    ASSERT_EQ( "0.5",calc.getResult("1/2"));
    ASSERT_EQ( "10.16666698",calc.getResult("1*2+6*6^-2+8"));
    ASSERT_EQ( "246912",calc.getResult("2*123456"));
    calc.setPrecision(3);
    ASSERT_EQ( "0.333",calc.getResult("1/3"));
}

TEST(Calculations,doubleTest) {
    Calculator<float> calc;

    calc.setPrecision(10);
    ASSERT_EQ( "0.5",calc.getResult("1/2"));
    ASSERT_EQ( "10.16666698",calc.getResult("1*2+6*6^-2+8"));
    ASSERT_EQ( "246912",calc.getResult("2*123456"));
    calc.setPrecision(3);
    ASSERT_EQ( "0.333",calc.getResult("1/3"));

    calc.setPrecision(20);
    ASSERT_EQ( "3.0517578125e-05",calc.getResult("1/2^15"));

    calc.setPrecision(200);
    ASSERT_EQ( "8.2718061255302767487140869206996285356581211090087890625e-25",calc.getResult("1/2^80"));

    ASSERT_EQ( "-1.265625",calc.getResult("((( 1 /2/4+2^-6*7 *cos(0)+ 9 /-4.5))+2/4)"));

}
