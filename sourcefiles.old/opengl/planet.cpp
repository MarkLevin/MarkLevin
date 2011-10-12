#include <GL/glut.h>

static int year=0,day=0;

void init (void)
{
	glClearColor(0,0,0,0);
	glShadeModel(GL_SMOOTH);
	
	GLfloat mat_specular [] = {1,1,1,1};
	GLfloat mat_shininess [] = {50};
	GLfloat light_position [] = {1,1,1,0};
	GLfloat white_light[] = {0.2,0,1,1};
	GLfloat lmodel_ambient [] = {0.1,0.1,0.1,1.0};
	glClearColor(0,0,0,0);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLightfv(GL_LIGHT0,GL_POSITION,light_position);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,white_light);
	glLightfv(GL_LIGHT0,GL_SPECULAR,white_light);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0,0);
	glPushMatrix();
	glutSolidSphere(1.0,200,100);
	glRotatef((GLfloat)year,0,1,0);
	glTranslatef(2,0,0);
	glRotatef((GLfloat)day,0,1,0);
	glColor3f(0,1,0);
	glutSolidSphere(0.2,100,50);
	glPopMatrix();
	glutSwapBuffers();
}
void reshape(int w,int h)
{
	glViewport(0,0,(GLsizei)w,(GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0,(GLfloat)w/(GLfloat)h,1,20);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(2,3,4,0,0,0,0,1,0);
}

void keyboard(unsigned char key, int  x, int y)
{
	switch(key)
	{
	case 'd':
		day=(day+10)%360;
		glutPostRedisplay();
		break;
	case 'D':
		day=(day-10)%360;
		glutPostRedisplay();
		break;
	case 'y':
		year=(year+5)%360;
		glutPostRedisplay();
		break;
	case 'Y':
		year=(year-5)%360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}
int main(int argc ,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
