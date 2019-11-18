#define GL_SILENCE_DEPRECATION
#include<stdio.h>
#include<OpenGL/gl.h>
#include<GLUT/glut.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#define PI 3.142857

class coordinate
{
public:
    float x,y;
    coordinate()
    {
    x=0;
    y=0;
    }
   coordinate(float x1,float y1)
    {
        x=x1;
        y=y1;
    }
};

coordinate c1(40,69.282);
coordinate c2(-80,0);
coordinate c3(51.423,-61.283);
coordinate c4(40,69.282);
coordinate c5(-80,0);
coordinate c6(51.423,-61.283);

coordinate myRotate(coordinate p, float theta)
{
    float rtheta=3.14/180.0 * theta;
    coordinate c2;
    c2.x=p.x*cos(rtheta)-p.y*sin(rtheta);
    c2.y=p.x*sin(rtheta)+p.y*cos(rtheta);
    return c2;
}


void Initialization (void)
{

    glClearColor(1.0, 1.0, 1.0, 1.0);
    glPointSize(2.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-780, 780, -420, 420);
}

void draw(void)
{
glClear(GL_COLOR_BUFFER_BIT);
float x_1,y_1,x_2,y_2,i;
glBegin(GL_POINTS);

glColor3f(0.0, 0.0, 1.0);
for ( i = 0; i < (2 * PI); i += 0.001) {
	x_1 = 80 * cos(i);
    y_1 = 80 * sin(i);

    x_2 = 10 * cos(i);
    y_2 = 10 * sin(i);

    glVertex2i(x_1+200,y_1);
    glVertex2f(x_2+200,y_2);

}
glEnd();
glFlush();

glBegin(GL_LINES);
glVertex2i(200,0);
glVertex2i(c1.x+200,c1.y);
glEnd();
glFlush();


glBegin(GL_LINES);
glVertex2i(200,0);
glVertex2i(c2.x+200,c2.y);
glEnd();
glFlush();


glBegin(GL_LINES);
glVertex2i(200,0);
glVertex2i(c3.x+200,c3.y);
glEnd();
glFlush();



glBegin(GL_POINTS);

glColor3f(1.0, 0.0, 1.0);
for ( i = 0; i < (2 * PI); i += 0.001) {
x_1 = 80 * cos(i);
        y_1 = 80 * sin(i);

        x_2 = 10 * cos(i);
        y_2 = 10 * sin(i);

        glVertex2i(x_1-200,y_1);
        glVertex2f(x_2-200,y_2);

}
glEnd();
glFlush();

glBegin(GL_LINES);
glVertex2i(-200,0);
glVertex2i(c4.x-200,c4.y);
glEnd();
glFlush();


glBegin(GL_LINES);
glVertex2i(-200,0);
glVertex2i(c5.x-200,c5.y);
glEnd();
glFlush();


glBegin(GL_LINES);
glVertex2i(-200,0);
glVertex2i(c6.x-200,c6.y);
glEnd();
glFlush();
glutSwapBuffers();
}

void roatate_function();
void func(int x)
{
    roatate_function();
    glutPostRedisplay();
}
void roatate_function()
{


    c1=myRotate(c1,-10);
    c2=myRotate(c2,-10);
    c3=myRotate(c3,-10);

    c4=myRotate(c4,+20);
    c5=myRotate(c5,+20);
    c6=myRotate(c6,+20);

	glutTimerFunc(1,func,100);
}



int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB |GLUT_DOUBLE);
    glutInitWindowSize(1400, 800);
    glutCreateWindow("Third_Test");
    glutTimerFunc(1000,func,100);
    Initialization();
    glutDisplayFunc(draw);
	glutMainLoop();
}