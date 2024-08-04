#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "my_primitives.h"
#include "my_functions.h"
#include "drawings.h"
#include "drawingC3.h"

using namespace std;

float x=2.0f;
float angle=0.0f;
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //GL_DEPTH_BUFFER_BIT: Visibility algorithm (z-buffer)
    glLoadIdentity();
    translate(2,-2,-3);
    
    //translate(x, x, -4);
    rotatey(angle);
    //scale(12, 12, 1);

    //elipse(0.5, 0.5, 2*M_PI);
    //cylinder(1, 2);
    //glutSolidCube(2);
    drawC3();
    //island();

    glutSwapBuffers(); // This is used instead of flush because of the animation
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //orthogonal(-2, 2, -2, 2, -1, 1);
    perspective(-2, 2, -2, 2, 0.5, 10);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/30, timer, 0);
    x-=0.01;
    angle+=0.5;
}

int main(int argc, char** argv){
    // Rasterization algorithms
    auto coords_dda = DDA(3,2,0,15,5,5);
    auto coords_b   = bresenham(3,2,0,15,5,5);
    cout << "Testing DDA algorithm:\n";
    for (int i = 0; i < coords_dda.first.size(); ++i) {
        cout << "(" << coords_dda.first[i] << ", " << coords_dda.second[i] << ")\n";
    }
    cout << "Testing Bresenham algorithm:\n";
    for (int i = 0; i < coords_b.first.size(); ++i) {
        cout << "(" << coords_b.first[i] << ", " << coords_b.second[i] << ")\n";
    }


    glutInit(&argc, argv);                       
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // GLUT_DEPTH: Visibility algorithm (z-buffer)
    glutInitWindowSize(400, 400);             
    glutInitWindowPosition(100, 100);       
    glutCreateWindow("OpenGL Test");        
    glClearColor(0.68, 0.85, 0.90, 1.0);
    glEnable(GL_DEPTH_TEST); // Visibility algorithm (z-buffer)


    // Phong and Gouraud models
    glEnable(GL_LIGHTING);   
    glEnable(GL_LIGHT0);     
    glShadeModel(GL_SMOOTH); // Gouraud shading. This smooth shading is already the dafault. 
    GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f }; 
    GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f }; 
    GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };  
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 
    GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
    GLfloat mat_shininess[] = { 100.0f }; 
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);


    glutDisplayFunc(display);               
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();                         
    return 0;
}