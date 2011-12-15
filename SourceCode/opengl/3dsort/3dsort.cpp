#include <iostream>     
#include <cstdlib>
#include <ctime>
#include <GL/glut.h>
#define D(a) cout<< #a " = ["<<a<<"] at line ["<<__LINE__<<"] "<<endl;
using namespace std;

typedef unsigned int ui;
typedef unsigned char uc;

const ui MAXSIZE=128;
const ui MAX=10000000;


ui insertionSortNumber[MAXSIZE];
ui bubbleSortNumber[MAXSIZE];
ui quickSortNumber[MAXSIZE];
ui mergeSortNumber[MAXSIZE];
ui shellSortNumber[MAXSIZE];
ui bubble2SortNumber[MAXSIZE];

void display();
void init();
void keyboard(uc,int,int);
void mergeSort(int,int);
void merge(int,int,int);

int m,n;
int flag=0;

void init()
{
  m=0;
  n=MAXSIZE-1;
  srand(time(0));
  for(int i=0;i<MAXSIZE;i++)
  {
    bubble2SortNumber[i]=shellSortNumber[i]=mergeSortNumber[i]=quickSortNumber[i]=bubbleSortNumber[i]=insertionSortNumber[i]=rand()%MAX;
  }
}

void insertionSort()
{
  flag=1;
  for(m=1;m<MAXSIZE;m++)
  {
    int key=insertionSortNumber[m];
    n=m-1;
    while(n>=0&&insertionSortNumber[n]>key)
    {
      
      insertionSortNumber[n+1]=insertionSortNumber[n];
      n--;
      display();
    }
    insertionSortNumber[n+1]=key;
  }
  m=0;
  n=MAXSIZE-1;flag=0;
}
void bubbleSort()
{
    flag=2;
    for(m=0;m<MAXSIZE;m++)
    {
        for(n=MAXSIZE-1;n>m;n--)
        {
            if(bubbleSortNumber[n]<bubbleSortNumber[n-1])
            {
                int temp=bubbleSortNumber[n];
                bubbleSortNumber[n]=bubbleSortNumber[n-1];
                bubbleSortNumber[n-1]=temp;
                n--;
                display();
                n++;
            }
        }
    }
    m=0;
    n=MAXSIZE-1;flag=0;
}
void bubble2Sort()
{
    flag=6;
    int temp;
    int left=1;
    int right=MAXSIZE-1;
    int t;
    do
    {
        for(int i=right;i>=left;i--)
        {
            if(bubble2SortNumber[i]<bubble2SortNumber[i-1])
            {
                temp=bubble2SortNumber[i];
                bubble2SortNumber[i]=bubble2SortNumber[i-1];
                bubble2SortNumber[i-1]=temp;
                t=i;
                n=i-1;
                m=left-1;
                display();
            }
        }
        left=t+1;
        for(int i=left;i<right+1;i++)
        {
            if(bubble2SortNumber[i]<bubble2SortNumber[i-1])
            {
                temp=bubble2SortNumber[i];
                bubble2SortNumber[i]=bubble2SortNumber[i-1];
                bubble2SortNumber[i-1]=temp;
                t=i;
                n=i;
                m=right;
                display();
            }
        }
        right=t-1;
    }
    while(left<=right);

    m=0;
    n=MAXSIZE-1;
    flag=0;
}

void quickSort(int left,int right)
{
    flag=3;
    int i,j;
    int middle,temp;
    i=left;j=right;
    middle=quickSortNumber[(left+right)/2];
    do
    {
        while((quickSortNumber[i]<middle)&&(i<right)) i++;
        while((quickSortNumber[j]>middle)&&(j>left)) j--;
        if(i<=j)
        {
            temp=quickSortNumber[i];
            quickSortNumber[i]=quickSortNumber[j];
            quickSortNumber[j]=temp;
            i++;
            j--;
            n=i;
            m=j;
            display();
        }
    }while(i<=j);

    if(left<j)
        quickSort(left,j);
    if(right>i)
        quickSort(i,right);
    m=0;
    n=MAXSIZE-1;
    flag=0;
}
void mergeSort(int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        mergeSort(p,q);
        mergeSort(q+1,r);
        merge(p,q,r);
    }
}
void merge(int p,int q,int r)
{
    flag=4;
    m=r;
    n=p;
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int L[n1+1];
    int R[n2+1];

    for(i=0;i<n1;i++)
        L[i]=mergeSortNumber[p+i];
    for(j=0;j<n2;j++)
        R[j]=mergeSortNumber[q+j+1];
    L[n1]=100000000;
    R[n2]=100000000;
    i=0;j=0;

    for(int k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            mergeSortNumber[k]=L[i];
            i++;
        }
        else
        {
            mergeSortNumber[k]=R[j];
            j++;
        }
        display();
    }
    m=0;
    n=MAXSIZE-1;
    flag=0;
}

void shellSort()
{
    flag=5;
    int gap,j;
    for(gap=MAXSIZE/2;gap>0;gap/=2)
    {
        for(j=gap;j<MAXSIZE;++j)
        {
            if(shellSortNumber[j]<shellSortNumber[j-gap])
            {
                int temp=shellSortNumber[j];
                int k=j-gap;
                while(k>=0&&shellSortNumber[k]>temp)
                {
                    shellSortNumber[k+gap]=shellSortNumber[k];
                    k-=gap;
                }
                n=gap;
                m=j;
                shellSortNumber[k+gap]=temp;
                display();
            }
        }
    }
    flag=0;
    m=0;
    n=MAXSIZE-1;
}

void display()
{


  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.5,1,1);
  glLineWidth(1);
  glEnable(GL_LINE_STIPPLE);
  glLineStipple(1,0x0F0F);
  glBegin(GL_LINES);
  {
      glVertex2d(1/3.0,1.0);
      glVertex2d(1/3.0,-1.0);
  }
  glEnd();
  glBegin(GL_LINES);
  {
      glVertex2d(-1/3.0,1.0);
      glVertex2d(-1/3.0,-1.0);
  }
  glEnd();
  glBegin(GL_LINES);
  {
      glVertex2d(-1.0,0.0);
      glVertex2d(1.0,0.0);
  }
  glEnd();
  glDisable(GL_LINE_STIPPLE);
  
  ui t=clock();
  while( clock()-t<50000) ;
  glColor3f(0.1,0.5,0.8);
  glLineWidth(2);
  for(int i=0;i<MAXSIZE;i++)
  {
    if(flag==1) 
        glColor3f(0.4,0.3,0.9);
    if(i==m) glColor3f(0.1,1,0.2);
    if(i==n) glColor3f(1,0.2,0.4);
    glBegin(GL_LINES);
    {
      glVertex2d(1/3.0+2.0/3*(i+2)/(MAXSIZE+3),insertionSortNumber[i]*1.0/MAX);
      glVertex2d(1/3.0+2.0/3*(i+2)/(MAXSIZE+3),0.0);
    }glEnd();
    glColor3f(0.1,0.5,0.8);

    if(flag==2)
        glColor3f(0.4,0.3,0.9);
    if(i==m-1) glColor3f(0.1,1,0.2);
    if(i==n) glColor3f(1,0.2,0.4);
    glBegin(GL_LINES);
    {
        glVertex2d(-1/3.0+2.0/3*(i+2)/(MAXSIZE+3),bubbleSortNumber[i]*1.0/MAX);
        glVertex2d(-1/3.0+2.0/3*(i+2)/(MAXSIZE+3),0.0);
    }
    glEnd();
    glColor3f(0.1,0.5,0.8);

    if(flag==3) glColor3f(0.4,0.3,0.9);
    if(i==m) glColor3f(0.1,1,0.2);
    if(i==n) glColor3f(1,0.2,0.4);
    glBegin(GL_LINES);
    {
        glVertex2d(-1.0+2.0/3*(i+2)/(MAXSIZE+3),quickSortNumber[i]*1.0/MAX);
        glVertex2d(-1.0+2.0/3*(i+2)/(MAXSIZE+3),0.0);
    }
    glEnd();
    glColor3f(0.1,0.5,0.8);

    if(flag==4) glColor3f(0.4,0.3,0.9);
    if(i==m) glColor3f(0.1,1,0.2);
    if(i==n) glColor3f(1,0.2,0.4);
    glBegin(GL_LINES);
    {
        glVertex2d(-1.0+2.0/3*(i+2)/(MAXSIZE+3),-1.0+mergeSortNumber[i]*1.0/MAX);
        glVertex2d(-1.0+2.0/3*(i+2)/(MAXSIZE+3),-1.0);
    }
    glEnd();
    glColor3f(0.1,0.5,0.8);

    if(flag==5) glColor3f(0.4,0.3,0.9);
    if(i==m) glColor3f(0.1,1,0.2);
    if(i==n) glColor3f(1,0.2,0.4);
    glBegin(GL_LINES);
    {
        glVertex2d(-1/3.0+2.0/3*(i+2)/(MAXSIZE+3),-1.0+shellSortNumber[i]*1.0/MAX);
        glVertex2d(-1/3.0+2.0/3*(i+2)/(MAXSIZE+3),-1.0);
    }
    glEnd();
    glColor3f(0.1,0.5,0.8);
    

    if(flag==6) glColor3f(0.4,0.3,0.9);
    if(i==m) glColor3f(0.1,1,0.2);
    if(i==n) glColor3f(1,0.2,0.4);
    glBegin(GL_LINES);
    {
        glVertex2d(1/3.0+2.0/3*(i+2)/(MAXSIZE+3),-1.0+bubble2SortNumber[i]*1.0/MAX);
        glVertex2d(1/3.0+2.0/3*(i+2)/(MAXSIZE+3),-1.0);
    }
    glEnd();
    glColor3f(0.1,0.5,0.8);
  }
  glutSwapBuffers();
}

int prevkey=0;
void keyboard(uc key, int x, int y)
{
  switch(prevkey)
  {
  case 'i':
      if(key=='s')
      {
        insertionSort();
        display();
      }
      else if(key=='r')
      {
          for(int i=0;i<MAXSIZE;i++)
              insertionSortNumber[i]=rand()%MAX;
          display();
      }
    break;
  case 'b':
    if(key=='s')
    {
        bubbleSort();
        display();
    }
    else if(key=='r')
    {
        for(int i=0;i<MAXSIZE;i++)
            bubbleSortNumber[i]=rand()%MAX;
        display();
    }
    break;
  case 'q':
    if(key=='s')
    {
        quickSort(0,MAXSIZE-1);
        display();
    }
    else if(key=='r')
    {
        for(int i=0;i<MAXSIZE;i++)
            quickSortNumber[i]=rand()%MAX;
        display();
    }
    break;
  case 'm':
    if(key=='s')
    {
        mergeSort(0,MAXSIZE-1);
        display();
    }
    else if(key=='r')
    {
        for(int i=0;i<MAXSIZE;i++)
            mergeSortNumber[i]=rand()%MAX;
        display();
    }
    break;
  case 'h':
    if(key=='s')
    {
        shellSort();
        display();
    }
    else if(key=='r')
    {
        for(int i=0;i<MAXSIZE;i++)
            shellSortNumber[i]=rand()%MAX;
        display();
    }
    break;
  case 'n':
    if(key=='s')
    {
        bubble2Sort();
        display();
    }
    else if(key=='r')
    {
        for(int i=0;i<MAXSIZE;i++)
            bubble2SortNumber[i]=rand()%MAX;
        display();
    }
  case 'a':
    if(key=='s')
    {
        quickSort(0,MAXSIZE-1);
        bubbleSort();
        insertionSort();
        mergeSort(0,MAXSIZE-1);
        shellSort();
        bubble2Sort();
        display();
    }
    if(key=='r')
    {
        for(int i=0;i<MAXSIZE;i++)
            quickSortNumber[i]=bubbleSortNumber[i]=insertionSortNumber[i]=mergeSortNumber[i]=shellSortNumber[i]=bubble2SortNumber[i]=rand()%MAX;
        display();
    }
    if(key=='t')
    {
        for(int i=0;i<MAXSIZE;i++)
        {
            quickSortNumber[i]=rand()%MAX;
            bubbleSortNumber[i]=random()%MAX;
            insertionSortNumber[i]=random()%MAX;
            mergeSortNumber[i]=random()%MAX;
            shellSortNumber[i]=random()%MAX;
            bubble2SortNumber[i]=random()%MAX;
        }
        display();

    }
    break;
  }
  prevkey=key;
}


int main(int argc, char ** argv){
  init();
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

  glutCreateWindow("3D sorts");
  glutFullScreen();
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  
}
