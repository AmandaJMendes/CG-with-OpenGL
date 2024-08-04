#include <GL/glut.h>
#include <iostream>
#include <math.h>

/*
The following functions were developed for experimentation with OpenGL
They may be useful for our final design, but they require some revision
    - We must use our own functions for translation and rotation
*/

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

void triangle(float base, float height){
    glBegin(GL_TRIANGLES);
    glVertex3f(0.0f, height/2, 0.0f);
    glVertex3f(-base/2, -height/2, 0.0f);
    glVertex3f(base/2, -height/2, 0.0f);
    glEnd();
}

void triangular_prism(float base, float height, float depth){
    glPushMatrix();
    glTranslatef(0, 0, depth/2);
    triangle(base, height);
    glTranslatef(0, 0, -depth);
    triangle(base, height);
    glPopMatrix();

    glBegin(GL_QUADS);
    glVertex3f(0.0f, height/2, depth/2);
    glVertex3f(0.0f, height/2, -depth/2);
    glVertex3f(base/2, -height/2, -depth/2);
    glVertex3f(base/2, -height/2, depth/2);

    glVertex3f(0.0f, height/2, depth/2);
    glVertex3f(0.0f, height/2, -depth/2);
    glVertex3f(-base/2, -height/2, -depth/2);
    glVertex3f(-base/2, -height/2, depth/2);

    glVertex3f(base/2, -height/2, depth/2);
    glVertex3f(base/2, -height/2, -depth/2);
    glVertex3f(-base/2, -height/2, -depth/2);
    glVertex3f(-base/2, -height/2, depth/2);
    glEnd();
}

void hexagon(float radius){
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i){
        glVertex3f(radius * cosf(i * M_PI / 3), radius * sinf(i * M_PI / 3), 0.0f);
    }
    glEnd();
}

void hexagonal_prism(float radius, float height){
    glPushMatrix();
    glTranslatef(0, 0, height/2);
    hexagon(radius);
    glTranslatef(0, 0, -height);
    hexagon(radius);
    glPopMatrix();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 6; ++i){
        glVertex3f(radius * cosf(i * M_PI / 3), radius * sinf(i * M_PI / 3), height/2);
        glVertex3f(radius * cosf(i * M_PI / 3), radius * sinf(i * M_PI / 3), -height/2);
    }
    glEnd();
}

void custom_hexagonal_prism(float *edges, float height){
    glPushMatrix();
    glTranslatef(0, 0, height/2);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i){
        glVertex3f(edges[i] * cosf(i * M_PI / 3), edges[i] * sinf(i * M_PI / 3), 0.0f);
    }
    glEnd();
    glTranslatef(0, 0, -height);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; ++i){
        glVertex3f(edges[i] * cosf(i * M_PI / 3), edges[i] * sinf(i * M_PI / 3), 0.0f);
    }
    glEnd();
    glPopMatrix();

    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i <= 6; ++i){
        glVertex3f(edges[i % 6] * cosf(i * M_PI / 3), edges[i % 6] * sinf(i * M_PI / 3), height/2);
        glVertex3f(edges[i % 6] * cosf(i * M_PI / 3), edges[i % 6] * sinf(i * M_PI / 3), -height/2);
    }
    glEnd();
}