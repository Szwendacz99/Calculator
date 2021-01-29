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
    std::cout << "Starting MainWindow object" << std::endl;

    prepareWindow();
    prepareCalculator();
}

void MainWindow::showWindow() {
    std::cout << "Showing window" << std::endl;
    this->show();
}

MainWindow::~MainWindow() {
    ((Calculator<float>*) calculator)->~Calculator();
    std::cout << "MainWindow object destroyed!" << std::endl;
}

void MainWindow::prepareWindow() {

    textInput = new QTextEdit;

    std::cout << "Preparing widgets" << std::endl;
    QVBoxLayout* mainLayout = new QVBoxLayout;
    QHBoxLayout* numericsColumnsLayout = new QHBoxLayout;
    QVBoxLayout* column1Layout = new QVBoxLayout;
    QVBoxLayout* column2Layout = new QVBoxLayout;
    QVBoxLayout* column3Layout = new QVBoxLayout;
    QVBoxLayout* column4Layout = new QVBoxLayout;
    QVBoxLayout* numberTypePanel = new QVBoxLayout;

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

    QPushButton* buttonInt = new QPushButton("Integer");
    QPushButton* buttonLong = new QPushButton("Long");
    QPushButton* buttonFloat = new QPushButton("Float");
    QPushButton* buttonDouble = new QPushButton("Double");


    QPushButton* plus = new QPushButton("+");
    QPushButton* minus = new QPushButton("-");
    QPushButton* multiply = new QPushButton("*");
    QPushButton* divide = new QPushButton("/");
    QPushButton* power = new QPushButton("pow");

    QPushButton* quitButton = new QPushButton("Quit");
    QPushButton* equals = new QPushButton("=");

    liveResult = new QLabel("0");
    staticResult = new QLabel("0");

    liveResult->setAlignment(Qt::AlignRight);
    staticResult->setAlignment(Qt::AlignRight);

    liveResult->setMargin(3);
    staticResult->setMargin(3);

    column1Layout->addWidget(one);
    column1Layout->addWidget(four);
    column1Layout->addWidget(seven);
    column1Layout->addWidget(quitButton);

    column2Layout->addWidget(two);
    column2Layout->addWidget(five);
    column2Layout->addWidget(eight);
    column2Layout->addWidget(zero);

    column3Layout->addWidget(three);
    column3Layout->addWidget(six);
    column3Layout->addWidget(nine);
    column3Layout->addWidget(power);

    column4Layout->addWidget(plus);
    column4Layout->addWidget(minus);
    column4Layout->addWidget(multiply);
    column4Layout->addWidget(divide);

    numberTypePanel->addWidget(buttonInt);
    numberTypePanel->addWidget(buttonLong);
    numberTypePanel->addWidget(buttonFloat);
    numberTypePanel->addWidget(buttonDouble);

    numericsColumnsLayout->addItem(column1Layout);
    numericsColumnsLayout->addItem(column2Layout);
    numericsColumnsLayout->addItem(column3Layout);
    numericsColumnsLayout->addItem(column4Layout);
    numericsColumnsLayout->addItem(numberTypePanel);

    QObject::connect(quitButton,SIGNAL(clicked()), qApp, SLOT(quit()));

    QObject::connect(equals,&QPushButton::pressed, this, &MainWindow::handleButton);
    QWidget* centralWidget = new QWidget();
    centralWidget->setLayout(mainLayout);
    this->setCentralWidget(centralWidget);

    mainLayout->addWidget(textInput);
    mainLayout->addWidget(liveResult);
    mainLayout->addWidget(staticResult);
    mainLayout->addWidget(equals);
    mainLayout->addLayout(numericsColumnsLayout);
    std::cout << "Finished preparing widgets" << std::endl;

}


//string math = "2^(((22*5/2)+4*(2+4)+2*((2*(5/4)))+(2.5-4.6^2.6^(-0.2)) *(2^(24-6/2^5)+ 5^2^2+ 15/5*20*50/50+345/2 + 2 + 6/3 * 4 +6 + 5*2))/100000)";
std::string math = " 254*55646/2+(55+66*77)+2^32";

void MainWindow::prepareCalculator() {
    calculator = new Calculator<float>();

    //temporary START
    textInput->setText(math.c_str());
    staticResult->setText(QString(calculator->getResult(math).c_str()));
    liveResult->setText(QString(calculator->getResult(math).c_str()));
    //temporary END

}

void MainWindow::handleButton() {
    qDebug() << "Clicked button";
}
