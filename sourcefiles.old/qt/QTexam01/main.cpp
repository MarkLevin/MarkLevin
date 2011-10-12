#include <QtGui/QApplication>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *windows=new QWidget;
    QLabel *label1= new QLabel("<p><i><h2><font color=gray>Ben</font><h2></i></p><p>I Love YOU<\p>");
    QLabel *label2= new QLabel(" More Than YOU Can Imagine");
    QVBoxLayout *layout= new QVBoxLayout;
    layout->addWidget(label1);
    layout->addWidget(label2);
    windows->setLayout(layout);
    windows->show();
    return a.exec();
}
