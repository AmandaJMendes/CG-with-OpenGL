#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include "my_primitives.h"
#include "my_functions.h"
#include "drawings.h"

float x=2.0f;
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    translate(2,-2,-3);
    
    //translate(x, x, -4);
    rotatey(M_PI/9);
    //scale(12, 12, 1);

    //elipse(0.5, 0.5, 2*M_PI);
    //cylinder(1, 2);
    glutSolidCube(2);
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
    /////////////////////////////////////////////////////////////
    auto coords_dda = DDA(3,2,0,15,5,5);
    auto coords_b   = bresenham(3,2,0,15,5,5);
    std::cout << "Testing DDA algorithm:\n";
    for (int i = 0; i < coords_dda.first.size(); ++i) {
        std::cout << "(" << coords_dda.first[i] << ", " << coords_dda.second[i] << ")\n";
    }
    std::cout << "Testing Bresenham algorithm:\n";
    for (int i = 0; i < coords_b.first.size(); ++i) {
        std::cout << "(" << coords_b.first[i] << ", " << coords_b.second[i] << ")\n";
    }
    /////////////////////////////////////////////////////////////

    glutInit(&argc, argv);                       
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); 
    glutInitWindowSize(400, 400);             
    glutInitWindowPosition(100, 100);       
    glutCreateWindow("OpenGL Test");        
    
    glClearColor(0.68, 0.85, 0.90, 1.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);  // Enable the first light source

    // Set light properties
    GLfloat light_position[] = { 1.0f, 1.0f, 1.0f, 0.0f }; // Directional light from above
    GLfloat light_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f };  // No ambient light
    GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // White diffuse light
    GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White specular light
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

    // Set material properties for the cylinder
    GLfloat mat_ambient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // No ambient material
    GLfloat mat_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White diffuse material
    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // White specular material
    GLfloat mat_shininess[] = { 100.0f }; // Shininess value
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