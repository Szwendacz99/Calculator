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

    /// Label for displaying result while user writing
    QLabel* liveResult = nullptr;
    QLabel* staticResult = nullptr;

    /**
     * Sets up whole interface layouts
     */
    void prepareWindow();

    /**
     * initialize Calculator object with upcasting to
     * CalcTypeless class
     */
    void prepareCalculator();

    /**
     * Triggers calculation and puts result (or error info) text to
     * the given widget
     * @param widget QLabel widget in which text will be changed
     */
    void setResultText(QLabel* widget);

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

    /**
     * deletes last char in input text field
     */
    void backspaceAction();

};


#endif //CALCULATOR_MAINWINDOW_H
