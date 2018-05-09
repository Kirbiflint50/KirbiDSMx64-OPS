#include "mainhome.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        MainHome w;
        w.setWindowTitle("KirbiDSMx64");
        w.show();

    return a.exec();
}
