#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265
  
void display(){
	glColor3f(1,1,1);
	float radius = 20;
    float twoPI = 2 * PI;

    glBegin(GL_POINTS);

    for (float i = 0.0; i <= twoPI / 2; i += 0.001)
        glVertex2i((sin(i)*radius), (cos(i)*radius));

    glEnd();
    glBegin(GL_LINE_STRIP);
    glVertex2i(0,20);
    glVertex2i(-15,15);
    glVertex2i(-15,13);
    glVertex2i(-35,7);
    glVertex2i(-35,5);
    glVertex2i(-55,0);

    glVertex2i(-35,-5);
	glVertex2i(-35,-7);
	glVertex2i(-15,-13);
	glVertex2i(-15,-15);
    glVertex2i(0,-20);
    
    glEnd();
    glFlush(); 
}

void myinit(){
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
 glLoadIdentity();
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-500,500,-350,350);
}

int main(int argc,char** argv){
	 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB); 
 glutInitWindowSize(1000,700);
 glutInitWindowPosition(100,10);
 glutCreateWindow("Kame hame ha");
 myinit();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
