#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
	QApplication app( argc,argv);
	QLabel *label = new QLabel("笨笨我爱你");
	label->show();
	return app.exec();
}
