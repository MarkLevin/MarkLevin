#include <QtGui>
int main(int argc, char * argv[])
{
    QApplication app( argc, argv);
    QWidget *window = new QWidget;
    window->setWindowTitle("efe");
    QLabel *l1=new QLabel("Helloworld");
    QLabel *l2=new QLabel("ewafe");
    QPushButton *button1 = new QPushButton("Hello");
    QSpinBox *spinbox1 = new QSpinBox;
    QDial *dial1 = new QDial;
    QVBoxLayout *layout1 = new QVBoxLayout;

    layout1->addWidget(l1);
    layout1->addWidget(l2);
    layout1->addWidget(dial1);
    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(button1);
    layout2->addWidget(spinbox1);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addLayout(layout2);
    layout->addLayout(layout1);
    window->setLayout(layout);
    QObject::connect(dial1,SIGNAL(valueChanged(int)),l1,SLOT(setNum(int)));
    QObject::connect(button1,SIGNAL(pressed()),l2,SLOT(setNum(QString)));


    l1->show();
    window->show();
    return app.exec();
}
