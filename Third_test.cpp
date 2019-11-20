#define GL_SILENCE_DEPRECATION
#include<stdio.h>
#include<OpenGL/gl.h>
#include<GLUT/glut.h>
#include<math.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#define PI 3.142857
long int angle_1,angle_2;
int lowest = 5, highest = 15;


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

coordinate rotate(coordinate p, float theta)
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
	for(i = 0; i < (2 * PI); i += 0.001) {
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

void rotator_function(int value)
{
    c1=rotate(c1,-angle_1);
    c2=rotate(c2,-angle_1);
    c3=rotate(c3,-angle_1);

    c4=rotate(c4,+angle_2);
    c5=rotate(c5,+angle_2);
    c6=rotate(c6,+angle_2);

    glutTimerFunc(100,rotator_function,100);
    glutPostRedisplay();

}

int main(int argc, char **argv)
{
    srand(time(0));
    angle_1 = lowest + (rand() % 30);
    angle_2 = lowest + (rand() % 30);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB |GLUT_DOUBLE);
    glutInitWindowSize(1400, 800);
    glutCreateWindow("Third Test");
    glutTimerFunc(10,rotator_function,100);
    Initialization();
    glutDisplayFunc(draw);
    glutMainLoop();
}
