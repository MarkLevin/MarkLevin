#include <GL/glut.h>
static GLfloat spin =0.0;
void init(void)
{
	glClearColor(0.0,0.0,1.0,1.0);
	glShadeModel(GL_SMOOTH);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin,0.0,1.0,1.0);
	glColor3f(1.0,0,0);
	glRectf(-25.0,-25.0,25.0,25.0);
	glPopMatrix();
	glutSwapBuffers();
}
void spinDisplay(void)
{
	spin=spin+0.1;
	if(spin>360.0) spin=spin-360.0;
	glutPostRedisplay();
}
void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0,50.0,-50.0,50.0,-1.0,1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if (state==GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_RIGHT_BUTTON:
		if (state==GLUT_DOWN)
			glutIdleFunc(NULL);
	default:
		break;
	}
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(250,250);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutIdleFunc(spinDisplay);
	glutMainLoop();
	return 0;
}