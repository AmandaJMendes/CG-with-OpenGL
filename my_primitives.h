#include <GL/glut.h>
#include <iostream>
#include <math.h>

void elipse(float radius_x, float radius_y, float angle){
    glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0.0, 0.0, 0.0);
    for (float a = 0; a < angle; a+=0.01){
        glVertex3f(radius_x*cosf(a), radius_y*sinf(a), 0.0);
    }
    glEnd();
}
void cylinder(float radius, float height){
    glPushMatrix();
    glTranslatef(0, 0, height/2);
    elipse(radius, radius, 2*M_PI);
    glTranslatef(0, 0, -height);
    elipse(radius, radius, 2*M_PI);
    glBegin(GL_QUAD_STRIP);
    for (float angle = 0; angle < 2*M_PI; angle+=0.01){
        glVertex3f(radius*cosf(angle), radius*sinf(angle), 0);
        glVertex3f(radius*cosf(angle), radius*sinf(angle), height);
    }
    glEnd();
    glPopMatrix();
}

void rectangle(float length, float height){
    glBegin(GL_QUADS);
    glVertex3f( length/2,  height/2, 0);
    glVertex3f(-length/2,  height/2, 0);
    glVertex3f(-length/2, -height/2, 0);
    glVertex3f( length/2, -height/2, 0);
    glEnd();
}
void cuboid(float length, float height, float width){
    glPushMatrix();
    glTranslatef(0, 0, width/2);
    rectangle(length, height);
    glTranslatef(0, 0, -width);
    rectangle(length, height);  
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, height/2);
    rectangle(length, width);
    glTranslatef(0, 0, -height);
    rectangle(length, width);
    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(0, 0, length/2);
    rectangle(width, height);
    glTranslatef(0, 0, -length);
    rectangle(width, height);
    glPopMatrix();
    

}