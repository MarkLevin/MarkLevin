/*
 * =====================================================================================
 *
 *       Filename:  fractal.cpp
 *
 *    Description:  fractal opengl---
 *
 *        Version:  1.0
 *        Created:  10/20/2011 01:23:31 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <GL/glut.h>
#include <cmath>
#include <iostream>
using namespace std;

const double HALFWIDTH=0.8;
const double OFFSET=-0.22;

double x[20][10000][3];
double y[20][10000][3];
int depth=1;

void init()
{
    x[0][0][0]=-HALFWIDTH/2;
    y[0][0][0]=HALFWIDTH*sqrt(3)/6+OFFSET;
    x[0][0][1]=HALFWIDTH/2;
    y[0][0][1]=HALFWIDTH*sqrt(3)/6+OFFSET;
    x[0][0][2]=0;
    y[0][0][2]=-HALFWIDTH*sqrt(3)/3+OFFSET;
}

void display()
{
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.1,0.5,0.8);
    glLineWidth(1);
    /*  glBegin(GL_LINE_LOOP);
        glVertex2f(-HALFWIDTH,-HALFWIDTH*sqrt(3)/3+OFFSET);
        glVertex2f(HALFWIDTH,-HALFWIDTH*sqrt(3)/3+OFFSET);
        glVertex2f(0,HALFWIDTH*sqrt(3)*2/3+OFFSET);
    glEnd();*/
    glBegin(GL_POLYGON);
        glVertex2f(x[0][0][0],y[0][0][0]);
        glVertex2f(x[0][0][1],y[0][0][1]);
        glVertex2f(x[0][0][2],y[0][0][2]);
    glEnd();
       
 
    for(int dep=1;dep<depth;dep++)
    {
        int count=0;
        for(int j=0;j<pow(3,dep-1);j++)
        {
          x[dep][count][0]=(3*x[dep-1][j][0]+x[dep-1][j][1])/4.0;
          y[dep][count][0]=(3*y[dep-1][j][0]-y[dep-1][j][2])/2.0;
          x[dep][count][1]=(x[dep-1][j][0]+3*x[dep-1][j][1])/4.0;
          y[dep][count][1]=(3*y[dep-1][j][0]-y[dep-1][j][2])/2.0;
          x[dep][count][2]=(x[dep-1][j][1]+x[dep-1][j][0])/2.0;
          y[dep][count][2]=(y[dep-1][j][0]);


          glBegin(GL_POLYGON);
          {
              glVertex2f(x[dep][count][0],y[dep][count][0]);
              glVertex2f(x[dep][count][1],y[dep][count][1]);
              glVertex2f(x[dep][count][2],y[dep][count][2]);          }
          glEnd();
          count++;

          x[dep][count][0]=(5*x[dep-1][j][0]-x[dep-1][j][1])/4.0;
          y[dep][count][0]=(y[dep-1][j][0]+y[dep-1][j][2])/2.0;
          x[dep][count][1]=(3*x[dep-1][j][0]+x[dep-1][j][1])/4.0;
          y[dep][count][1]=(y[dep-1][j][0]+y[dep-1][j][2])/2.0;
          x[dep][count][2]=x[dep-1][j][0];
          y[dep][count][2]=y[dep-1][j][2];

          glBegin(GL_POLYGON);
          {
              glVertex2f(x[dep][count][0],y[dep][count][0]);
              glVertex2f(x[dep][count][1],y[dep][count][1]);
              glVertex2f(x[dep][count][2],y[dep][count][2]);
          }
          glEnd();
          count++;

          x[dep][count][0]=(-x[dep-1][j][0]+5*x[dep-1][j][1])/4.0;
          y[dep][count][0]=(y[dep-1][j][0]+y[dep-1][j][2])/2.0;
          x[dep][count][1]=(x[dep-1][j][0]+3*x[dep-1][j][1])/4.0;
          y[dep][count][1]=(y[dep-1][j][0]+y[dep-1][j][2])/2.0;
          x[dep][count][2]=x[dep-1][j][1];
          y[dep][count][2]=y[dep-1][j][2];
          glBegin(GL_POLYGON);
          {
              glVertex2f(x[dep][count][0],y[dep][count][0]);
              glVertex2f(x[dep][count][1],y[dep][count][1]);
              glVertex2f(x[dep][count][2],y[dep][count][2]);
          }
          glEnd();
          count++;
        }

        
    }

    glFlush();
}

void keyb(unsigned char key, int x, int y)
{
    switch(key){
    case 's':
        if(depth>=20) depth=20;
        depth++;
        glutPostRedisplay();
        break;
    case 'd':
        if(depth<=2) depth=2;
        depth--;
        glutPostRedisplay();
        break;
    }
}

int main(int argc, char **argv)
{
    init();
    glutInit(&argc,argv);
    //glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,800);
    glutCreateWindow("Fractal Triangle");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyb);
    glutMainLoop();
}

