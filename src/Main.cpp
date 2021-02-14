#include <iostream>
#include <Main.h>

using namespace std;

int main(int argv, char** args) {
    cout << "Starting!" << endl;

    QApplication app(argv,args);
    startWindow();

    return QApplication::exec();
}
