#include <QtGui/QApplication>
#include <QtGui/QMessageBox>
#include "glwidget.h"

int main(int argc, char **argv)
{
    Q_INIT_RESOURCE(framebufferobject2);

    QApplication a(argc, argv);
    if (!QGLFormat::hasOpenGL() || !QGLFramebufferObject::hasOpenGLFramebufferObjects()) {
	QMessageBox::information(0, "OpenGL framebuffer objects 2",
				 "This system does not support OpenGL/framebuffer objects.");
        return -1;
    }

    GLWidget widget(0);
    widget.resize(1900, 1000);
    widget.show();
    return a.exec();
}

