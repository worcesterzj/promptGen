/* main.cpp
 * by Anon TG
 * Last modification: 9/27/2020
 *
 * WHAT THIS DUMB PIECE OF SHIT DOES:
 * Provides entry point for the program.
*/

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
