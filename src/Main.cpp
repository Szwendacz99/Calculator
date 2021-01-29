#include <iostream>
#include <MainWindow.h>

using namespace std;

int main(int argv, char** args) {
    cout << "Starting!" << endl;

    QApplication app(argv,args);
    MainWindow window;
    window.show();

    return QApplication::exec();
}
