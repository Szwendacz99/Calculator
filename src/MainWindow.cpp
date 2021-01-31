//
// Created by maciej on 29.01.2021.
//

#include <iostream>
#include <MainWindow.h>
#include <QApplication>
#include <QPushButton>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QLabel>
#include <QtDebug>

MainWindow::MainWindow() {
    qDebug() << "Starting MainWindow object";

    prepareWindow();
    prepareCalculator();
}

MainWindow::~MainWindow() {
    ((Calculator<float>*) calculator)->~Calculator();
    qDebug() << "MainWindow object destroyed!";
}

#define BACKSPACE_SYMBOL "⌫"

void MainWindow::prepareWindow() {

    textInput = new QTextEdit;
    textInput->setStyleSheet("font-size:20px;font-family: Arial, Helvetica, sans-serif;");

    std::cout << "Preparing widgets" << std::endl;
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* numericsColumnsLayout = new QHBoxLayout;
    QHBoxLayout* equalsPanel = new QHBoxLayout;
    QVBoxLayout* column1Layout = new QVBoxLayout;
    QVBoxLayout* column2Layout = new QVBoxLayout;
    QVBoxLayout* column3Layout = new QVBoxLayout;
    QVBoxLayout* column4Layout = new QVBoxLayout;
    QVBoxLayout* column5Layout = new QVBoxLayout;

    QPushButton* zero = new QPushButton("0");
    QPushButton* one = new QPushButton("1");
    QPushButton* two = new QPushButton("2");
    QPushButton* three = new QPushButton("3");
    QPushButton* four = new QPushButton("4");
    QPushButton* five = new QPushButton("5");
    QPushButton* six = new QPushButton("6");
    QPushButton* seven = new QPushButton("7");
    QPushButton* eight = new QPushButton("8");
    QPushButton* nine = new QPushButton("9");

    QPushButton* plus = new QPushButton("+");
    QPushButton* minus = new QPushButton("-");
    QPushButton* multiply = new QPushButton("*");
    QPushButton* divide = new QPushButton("/");
    QPushButton* power = new QPushButton("^");

    QPushButton* openingBracket = new QPushButton("(");
    QPushButton* closingBracket = new QPushButton(")");
    QPushButton* sinus = new QPushButton("sin()");
    QPushButton* cosinus = new QPushButton("cos()");
    QPushButton* tangens = new QPushButton("tan()");

    QPushButton* quitButton = new QPushButton("Quit");
    QPushButton* equals = new QPushButton("=");
    QPushButton* backspaceButton = new QPushButton(BACKSPACE_SYMBOL);
    backspaceButton->setStyleSheet("font-size:10px;");

    liveResult = new QLabel("0");
    staticResult = new QLabel("0");

    liveResult->setAlignment(Qt::AlignRight);
    staticResult->setAlignment(Qt::AlignRight);

    liveResult->setMargin(3);
    staticResult->setMargin(3);

    column1Layout->addWidget(one);
    column1Layout->addWidget(four);
    column1Layout->addWidget(seven);
    column1Layout->addWidget(zero);
    column1Layout->addWidget(sinus);

    column2Layout->addWidget(two);
    column2Layout->addWidget(five);
    column2Layout->addWidget(eight);
    column2Layout->addWidget(openingBracket);
    column2Layout->addWidget(cosinus);

    column3Layout->addWidget(three);
    column3Layout->addWidget(six);
    column3Layout->addWidget(nine);
    column3Layout->addWidget(closingBracket);
    column3Layout->addWidget(tangens);

    column4Layout->addWidget(plus);
    column4Layout->addWidget(minus);
    column4Layout->addWidget(multiply);
    column4Layout->addWidget(divide);
    column4Layout->addWidget(power);

    column5Layout->addWidget(buttonInt);
    column5Layout->addWidget(buttonLong);
    column5Layout->addWidget(buttonFloat);
    column5Layout->addWidget(buttonDouble);
    column5Layout->addWidget(quitButton);

    numericsColumnsLayout->addItem(column1Layout);
    numericsColumnsLayout->addItem(column2Layout);
    numericsColumnsLayout->addItem(column3Layout);
    numericsColumnsLayout->addItem(column4Layout);
    numericsColumnsLayout->addItem(column5Layout);

    QObject::connect(quitButton,SIGNAL(clicked()), qApp, SLOT(quit()));


    QObject::connect(zero,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(one,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(two,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(three,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(four,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(five,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(six,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(seven,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(eight,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(nine,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(plus,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(minus,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(multiply,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(divide,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(power,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(openingBracket,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(closingBracket,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(sinus,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(cosinus,&QPushButton::pressed, this, &MainWindow::writingAction);
    QObject::connect(tangens,&QPushButton::pressed, this, &MainWindow::writingAction);

    QObject::connect(buttonInt,&QPushButton::pressed, this, &MainWindow::changeNumberType);
    QObject::connect(buttonLong,&QPushButton::pressed, this, &MainWindow::changeNumberType);
    QObject::connect(buttonFloat,&QPushButton::pressed, this, &MainWindow::changeNumberType);
    QObject::connect(buttonDouble,&QPushButton::pressed, this, &MainWindow::changeNumberType);

    QObject::connect(backspaceButton,&QPushButton::pressed, this, &MainWindow::backspaceAction);
    QObject::connect(equals,&QPushButton::pressed, this, &MainWindow::equalsAction);

    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

    mainLayout->addWidget(textInput);
    mainLayout->addWidget(liveResult);
    mainLayout->addWidget(staticResult);

    equalsPanel->addWidget(equals);
    equalsPanel->addWidget(backspaceButton);
    mainLayout->addLayout(equalsPanel);
    mainLayout->addLayout(numericsColumnsLayout);

    /// default setup
    buttonDouble->setStyleSheet(SELECTED);

    qDebug() << "Finished preparing widgets";

}


//string math = "2^(((22*5/2)+4*(2+4)+2*((2*(5/4)))+(2.5-4.6^2.6^(-0.2)) *(2^(24-6/2^5)+ 5^2^2+ 15/5*20*50/50+345/2 + 2 + 6/3 * 4 +6 + 5*2))/100000)";
std::string math = " 254*55646/2+(55+66*77)+2^32";

void MainWindow::prepareCalculator() {
    calculator = new Calculator<double>();

    //temporary START
    textInput->setText(math.c_str());
    staticResult->setText(QString(calculator->getResult(math).c_str()));
    liveResult->setText(QString(calculator->getResult(math).c_str()));
    //temporary END
}

void MainWindow::writingAction() {
    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender());
    textInput->setText(textInput->toPlainText() + buttonSender->text()) ;
    qDebug() << "Clicked writing button";
    setResultText(liveResult);
    textInput->setFocus();
}

void MainWindow::equalsAction() {
    setResultText(staticResult);
}

void MainWindow::backspaceAction() {
    size_t size = textInput->toPlainText().size();
    if( size == 0)
        return;
    textInput->setText(textInput->toPlainText().remove(size-1,1));
    setResultText(liveResult);
}

void MainWindow::setResultText(QLabel* widget) {
    std::string result;
    try {
        result = calculator->getResult(textInput->toPlainText().toStdString());
    } catch (const char* error) {
        result = error;
    } catch (...) {
        result = "";
    }
    widget->setText(QString(result.c_str()));
}

void MainWindow::changeNumberType() {
    const std::string type = qobject_cast<QPushButton*>(sender())->text().toStdString();
    free(calculator);

    buttonInt->setStyleSheet(NOT_SELECTED);
    buttonLong->setStyleSheet(NOT_SELECTED);
    buttonFloat->setStyleSheet(NOT_SELECTED);
    buttonDouble->setStyleSheet(NOT_SELECTED);

    if (type == "Integer") {
        calculator = new Calculator<int>;
        buttonInt->setStyleSheet(SELECTED);
    }else if (type =="Long") {
        calculator = new Calculator<long>;
        buttonLong->setStyleSheet(SELECTED);
    }else if (type =="Float") {
        calculator = new Calculator<float>;
        buttonFloat->setStyleSheet(SELECTED);
    }else if (type =="Double") {
        calculator = new Calculator<double>;
        buttonDouble->setStyleSheet(SELECTED);
    } else{
        throw "No such type of number!";
    }

    setResultText(liveResult);
    setResultText(staticResult);

}
