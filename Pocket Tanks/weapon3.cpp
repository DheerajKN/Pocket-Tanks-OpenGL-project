#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265
void display(){

   glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2i(70,30);
    glVertex2i(0,30);
     glVertex2i(0,10);
     glVertex2i(-70,10);
     glVertex2i(-70,-15);
     glVertex2i(-120,-15);
     glVertex2i(-45,-35);
     glVertex2i(-45,-10);
     glVertex2i(20,-10);
     glVertex2i(20,10);
    glVertex2i(70,30);
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
 glutCreateWindow("ThunderBolt");
 myinit();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
}