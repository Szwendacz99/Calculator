#include <iostream>
#include <string>
#include <QApplication>
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <calculator.h>

using namespace std;

//string math = "2^(((22*5/2)+4*(2+4)+2*((2*(5/4)))+(2.5-4.6^2.6^(-0.2)) *(2^(24-6/2^5)+ 5^2^2+ 15/5*20*50/50+345/2 + 2 + 6/3 * 4 +6 + 5*2))/100000)";
string math = " 254*55646/2+(55+66*77)+2^32";

int precision = 20;

int main(int argv, const char** args) {
    cout << "Starting!" << endl;

//    Calculator<long> calc(precision);

    CalcTypeless* calc = new Calculator<float>(precision);

    cout << "Result: " << calc->getResult(math) << endl;

    QApplication app(argv, const_cast<char **>(args));
//    QObject::connect(&quitButton,SIGNAL(clicked()), qApp, SLOT(quit()));

    QVBoxLayout mainLayout;
    QTextEdit textEdit;
    QHBoxLayout numericsColumnsLayout;
    QVBoxLayout column1Layout;
    QVBoxLayout column2Layout;
    QVBoxLayout column3Layout;
    QVBoxLayout column4Layout;
    QPushButton zero("0");
    QPushButton one("1");
    QPushButton two("2");
    QPushButton three("3");
    QPushButton four("4");
    QPushButton five("5");
    QPushButton six("6");
    QPushButton seven("7");
    QPushButton eight("8");
    QPushButton nine("9");

    QPushButton plus("+");
    QPushButton minus("-");
    QPushButton multiply("*");
    QPushButton divide("/");
    QPushButton power("pow");

    QPushButton quitButton("Quit");
    QPushButton equals("=");


    column1Layout.addWidget(&one);
    column1Layout.addWidget(&four);
    column1Layout.addWidget(&seven);
    column1Layout.addWidget(&quitButton);

    column2Layout.addWidget(&two);
    column2Layout.addWidget(&five);
    column2Layout.addWidget(&eight);
    column2Layout.addWidget(&zero);

    column3Layout.addWidget(&three);
    column3Layout.addWidget(&six);
    column3Layout.addWidget(&nine);
    column3Layout.addWidget(&power);

    column4Layout.addWidget(&plus);
    column4Layout.addWidget(&minus);
    column4Layout.addWidget(&multiply);
    column4Layout.addWidget(&divide);

    numericsColumnsLayout.addItem(&column1Layout);
    numericsColumnsLayout.addItem(&column2Layout);
    numericsColumnsLayout.addItem(&column3Layout);
    numericsColumnsLayout.addItem(&column4Layout);




    QWidget window;
    window.show();
    window.setLayout(&mainLayout);

    mainLayout.addWidget(&textEdit);
    mainLayout.addWidget(&equals);
    mainLayout.addLayout(&numericsColumnsLayout);
    return QApplication::exec();
//    return 0;
}
