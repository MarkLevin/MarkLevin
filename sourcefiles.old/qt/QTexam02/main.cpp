//#include "main.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char * argv[])
{
    QApplication a(argc,argv);
    QLabel *label = new QLabel("HELLOWORLD");
    label->show();
    return a.exec();
}
