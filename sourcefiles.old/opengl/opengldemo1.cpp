#include <GL/glut.h>
#include <iostream>
using namespace std;

void display(void)
{
	glColor3f(1.0,1.0,1.0);
	glPointSize(20);
	glLineWidth(5);
	glLineStipple(5,0xAAAA);
	glEnable(GL_LINE_STIPPLE);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_LINES);
	glVertex3f(0.25,0.25,0.0);
	glVertex3f(0.75,0.25,0.0);
	glVertex3f(0.75,0.75,0.0);
	glVertex3f(0.25,0.95,0.0);
	//glVertex3f(0.1,0.2,0.0);
	//glVertex2f(1,2);
	glEnd();
	//glutWireSphere(0.5,200000,3);
	glFlush();
}

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,1.0,0.0,1.0,-1.0,1.0);
}

int main(int argc,char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(700,700);
	glutInitWindowPosition(100,100);
	glutCreateWindow("hello");
	init();
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
}
