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

/**
 * Class for Main GUI window, everything is being prepared in constructor
 */
class MainWindow : public QMainWindow {
public:
    MainWindow();

    ~MainWindow() override;

private:
    CalcTypeless* calculator = nullptr;

    // QTextEdit widget for user input
    QTextEdit* textInput = nullptr;

    /// Label for displaying live result
    QLabel* liveResult = nullptr;
    QLabel* staticResult = nullptr;

    void prepareWindow();
    void prepareCalculator();

private slots:
    /**
     * action for all buttons used directly for writing math expression
     */
    void writingAction();

    /**
     * action for showing result in static display label,
     * used by button "equals"
     */
    void equalsAction();

};


#endif //CALCULATOR_MAINWINDOW_H
