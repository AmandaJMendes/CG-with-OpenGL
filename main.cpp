#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "my_primitives.h"
#include "my_functions.h"
#include "drawings.h"

float x=2.0f;
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    translate(x,-1,-4);
    
    //translate(x, x, -4);
    //rotatey(M_PI/6);
    //scale(12, 12, 1);

    //elipse(0.5, 0.5, 2*M_PI);
    cylinder(1, 2);
    //glutSolidCube(0.5);
    //island();

    glutSwapBuffers();
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //orthogonal(-2, 2, -2, 2, -1, 1);
    perspective(-2, 2, -2, 2, 0.5, 10);
    //glOrtho( -2, 2, -2, 2, -1, 1);
    //glFrustum(-4, 4, -4, 4, 1, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/30, timer, 0);
    x-=0.01;
}

int main(int argc, char** argv){
    glutInit(&argc, argv);                       
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // | GLUT_DEPTH); 
    glutInitWindowSize(400, 400);             
    glutInitWindowPosition(100, 100);       
    glutCreateWindow("OpenGL Test");        
    
    glClearColor(0.68, 0.85, 0.90, 1.0);
    //glEnable(GL_DEPTH_TEST);
    
    glutDisplayFunc(display);               
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();                         

    return 0;
}