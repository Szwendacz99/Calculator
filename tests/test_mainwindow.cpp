//
// Created by maciej on 14.02.2021.
//
#include <gtest/gtest.h>
#include <Main.h>


TEST(MainWindow,mainTest) {
    int val = 0;
    char** val2 = nullptr;
//    ASSERT_NO_THROW(QApplication app(val,val2));
    QApplication app(val,val2);
    ASSERT_NO_THROW(startWindow());
}