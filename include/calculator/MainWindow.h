//
// Created by maciej on 29.01.2021.
//

#ifndef CALCULATOR_MAINWINDOW_H
#define CALCULATOR_MAINWINDOW_H


#include <Calculator.h>
#include <QWidget>
#include <QTextEdit>
#include <QApplication>
#include <QLabel>
#include <QMainWindow>
#include <QRegExp>

class MainWindow : public QMainWindow {
public:
    MainWindow();

    void showWindow();

    ~MainWindow() override;

private:
    CalcTypeless* calculator = nullptr;
    QTextEdit* textInput = nullptr;
    QLabel* liveResult = nullptr;
    QLabel* staticResult = nullptr;

    void prepareWindow();
    void prepareCalculator();

private slots:
    void writingAction();
    void equalsAction();

};


#endif //CALCULATOR_MAINWINDOW_H
