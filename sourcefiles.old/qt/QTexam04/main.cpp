#include <QtGui>
int main(int argv ,char * argc[])
{
    QApplication Qapp(argv,argc);
    QLabel *label1 = new QLabel ("Helloworld");
    QLabel *label2 = new QLabel ("Hellowordl");
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(label1);
    layout->addWidget(label2);
    widget->setLayout(layout);
    widget->show();
    return Qapp.exec();
}
