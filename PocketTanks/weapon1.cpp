#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265

void d_circle(int h,int k, int r, int c1,int c2,int c3) {
	glColor3f(c1,c2,c3);
int i;
int lineAmount = 100; 
GLfloat twicePi = 2.0f * PI;
glBegin(GL_POLYGON);
for(i = 0; i <= lineAmount;i++) {
glVertex2i(h + (r * cos(i * twicePi / lineAmount)),k + (r* sin(i * twicePi / lineAmount)));
}
glEnd();
glBegin(GL_POINTS);
for(i=-500;i<500;i++){
glVertex2i(i,0);
}
glEnd();
glFlush();
}
void display(){
	d_circle(0,0,25,0,0,0);
	d_circle(0,0,5,1,0,1);
	glFlush();
}
void myinit(){
	glClearColor(1.0,1.0,1.0,1.0);
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
 glutCreateWindow("Canon Weapon");
 myinit();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}
