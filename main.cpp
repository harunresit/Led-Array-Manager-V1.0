#include "Modules/Screens/Headers/mainwindow.h"
#include "Modules/Screens/Headers/newsketch_screen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    newsketch_screen initscreen;
    initscreen.show();

    //MainWindow w;
    //w.show();

    return a.exec();
}
