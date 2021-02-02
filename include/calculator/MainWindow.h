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
#include <QSlider>


/**
 * CSS styles for selected and not selected buttons for
 * changing type of number
 */
#define NOT_SELECTED "font-weight:normal; color:;"
#define SELECTED "font-weight:bold; color:green;"

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

    QPushButton* buttonInt = new QPushButton("Integer");
    QPushButton* buttonLong = new QPushButton("Long");
    QPushButton* buttonFloat = new QPushButton("Float");
    QPushButton* buttonDouble = new QPushButton("Double");
    QSlider* precisionSlider = new QSlider(Qt::Vertical);
    QLabel* precisionLabel = new QLabel;

    /**
     * Set up whole interface layouts
     */
    void prepareWindow();

    /**
     * initialize Calculator object with upcasting to
     * CalcTypeless class
     */
    void prepareCalculator();

    /**
     * Trigger calculation and put result (or error info) text to
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
     * delete last char in input text field
     */
    void backspaceAction();

    /**
     * reinitialize calculator object to selected number type
     * after that refresh calculation and display result
     */
    void changeNumberType();

    /**
     * clear both static and live result, and input field
     */
    void clearAction();

    /**
     * action on user manually insert text to input field,
     * trigger printing live result
     */
    void newInputAction();

    void setPrecisionAction();

};


#endif //CALCULATOR_MAINWINDOW_H
