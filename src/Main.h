//
// Created by maciej on 14.02.2021.
//

#ifndef CALCULATOR_MAIN_H
#define CALCULATOR_MAIN_H

#include <MainWindow.h>
#include <clocale>


void startWindow() {
    // force using dot as decimal separator
    // because Qt messes this up
    setlocale(LC_NUMERIC, "C");

    QFont* font = new QFont("Arial");
    font->setStyleHint(QFont::Monospace);
    QApplication::setFont(*font);
    MainWindow* window = new MainWindow;
    window->show();
}


#endif //CALCULATOR_MAIN_H
