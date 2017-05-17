#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265
void display(){
glColor3f(1,1,1);
glBegin(GL_TRIANGLES);
glVertex2i(-90,0);
 glVertex2i(50,10);
 glVertex2i(50,-10);

 glVertex2i(45,35);
glVertex2i(70,25);
 glVertex2i(45,-35);
 
 glVertex2i(70,25);
 glVertex2i(45,-35);
 glVertex2i(70,-25);
 
 glVertex2i(148,55);
 glVertex2i(190,50);
 glVertex2i(155,35);

glVertex2i(45,35);
glVertex2i(148,55);
glVertex2i(70,25);

glVertex2i(70,25);
glVertex2i(148,55);
glVertex2i(158,50);


 glVertex2i(148,-55);
 glVertex2i(190,-50);
 glVertex2i(155,-35);

glVertex2i(45,-35);
glVertex2i(148,-55);
glVertex2i(70,-25);

glVertex2i(70,-25);
glVertex2i(148,-55);
glVertex2i(158,-50);

glVertex2i(65,5);
glVertex2i(130,8);
glVertex2i(65,-5);

glVertex2i(130,8);
glVertex2i(65,-5);
glVertex2i(130,-8);

glVertex2i(125,12);
glVertex2i(180,0);
glVertex2i(125,-12);
// glBegin(GL_LINE_STRIP);
// glVertex2i(-90,0);
// glVertex2i(50,10);
// glVertex2i(45,35);
// glVertex2i(190,50);
// glVertex2i(155,35);
// glVertex2i(150,40);
// glVertex2i(70,25);
// glVertex2i(75,5);
// glVertex2i(125,8);
// glVertex2i(125,12);
// glVertex2i(180,0);

// glVertex2i(125,-12);
// glVertex2i(125,-8);
// glVertex2i(75,-5);
// glVertex2i(70,-25);
// glVertex2i(150,-40);
// glVertex2i(155,-35);
// glVertex2i(190,-50);
// glVertex2i(45,-35);
// glVertex2i(50,-10);
// glVertex2i(-90,0);
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
 glutCreateWindow("Trident");
 myinit();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
