#include <iostream>
#include <MainWindow.h>
#include <clocale>

using namespace std;

int main(int argv, char** args) {
    cout << "Starting!" << endl;

    QApplication app(argv,args);


    // this is for restoring using dot as decimal separator
    // because Qt messes this up
    setlocale(LC_NUMERIC, "C");

    QFont font("Arial");
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);
    MainWindow window;
    window.show();

    return QApplication::exec();
}
