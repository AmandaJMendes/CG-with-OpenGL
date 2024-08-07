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

void calculateNormal(float v0[3], float v1[3], float v2[3], float normal[3]) {
    float vector1[3], vector2[3];

    vector1[0] = v1[0] - v0[0];
    vector1[1] = v1[1] - v0[1];
    vector1[2] = v1[2] - v0[2];

    vector2[0] = v2[0] - v0[0];
    vector2[1] = v2[1] - v0[1];
    vector2[2] = v2[2] - v0[2];

    normal[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    normal[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    normal[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];

    float length = sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);
    normal[0] /= length;
    normal[1] /= length;
    normal[2] /= length;
}

void right_angle_triangle(float base, float height) {
    float v0[3] = {0.0f, 0.0f, 0.0f};
    float v1[3] = {base, 0.0f, 0.0f};
    float v2[3] = {0.0f, height, 0.0f};
    float normal[3];

    calculateNormal(v0, v1, v2, normal);

    glBegin(GL_TRIANGLES);
    glNormal3fv(normal);
    glVertex3fv(v0);
    glVertex3fv(v1);
    glVertex3fv(v2);
    glEnd();
}


void right_angle_triangular_prism(float base, float height, float depth) {
    glPushMatrix();

    glTranslatef(0, 0, depth / 2);
    right_angle_triangle(base, height);

    glTranslatef(0, 0, -depth);
    right_angle_triangle(base, height);
    glPopMatrix();

    glBegin(GL_QUADS);
    float v0[3], v1[3], v2[3], normal[3];
    
    // Front face
    v0[0] = 0.0f; v0[1] = 0.0f; v0[2] = depth / 2;
    v1[0] = base; v1[1] = 0.0f; v1[2] = depth / 2;
    v2[0] = base; v2[1] = 0.0f; v2[2] = -depth / 2;
    calculateNormal(v0, v1, v2, normal);
    glNormal3fv(normal);
    glVertex3fv(v0);
    glVertex3fv(v1);
    glVertex3fv(v2);
    glVertex3f(0.0f, 0.0f, -depth / 2);
    
    v0[0] = 0.0f; v0[1] = 0.0f; v0[2] = depth / 2;
    v1[0] = 0.0f; v1[1] = height; v1[2] = depth / 2;
    v2[0] = 0.0f; v2[1] = height; v2[2] = -depth / 2;
    calculateNormal(v0, v1, v2, normal);
    glNormal3fv(normal);
    glVertex3fv(v0);
    glVertex3fv(v1);
    glVertex3fv(v2);
    glVertex3f(0.0f, 0.0f, -depth / 2);

    v0[0] = 0.0f; v0[1] = height; v0[2] = depth / 2;
    v1[0] = base; v1[1] = 0.0f; v1[2] = depth / 2;
    v2[0] = base; v2[1] = 0.0f; v2[2] = -depth / 2;
    calculateNormal(v0, v1, v2, normal);
    glNormal3fv(normal);
    glVertex3fv(v0);
    glVertex3fv(v1);
    glVertex3fv(v2);
    glVertex3f(0.0f, height, -depth / 2);

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

void drawFace(float vertices[][3], int numVertices) {
    if (numVertices < 3) return; 

    float normal[3];
    float v0[3] = {vertices[0][0], vertices[0][1], vertices[0][2]};
    float v1[3] = {vertices[1][0], vertices[1][1], vertices[1][2]};
    float v2[3] = {vertices[2][0], vertices[2][1], vertices[2][2]};
    calculateNormal(v0, v1, v2, normal);

    glBegin(GL_POLYGON);
    glNormal3f(normal[0], normal[1], normal[2]);
    for (int i = 0; i < numVertices; ++i) {
        glVertex3f(vertices[i][0], vertices[i][1], vertices[i][2]);
    }
    glEnd();
}

void drawTruncatedTriangularPrism(float topVertices[][3], float bottomVertices[][3], float height) {
    glPushMatrix();
    glTranslatef(0, 0, height / 2);
    drawFace(topVertices, 6);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -height / 2);
    drawFace(bottomVertices, 6);
    glPopMatrix();

    glBegin(GL_QUADS);
    for (int i = 0; i < 6; ++i) {
        int next = (i + 1) % 6;
        float v0[3] = {bottomVertices[i][0], bottomVertices[i][1], -height / 2};
        float v1[3] = {topVertices[i][0], topVertices[i][1], height / 2};
        float v2[3] = {topVertices[next][0], topVertices[next][1], height / 2};
        float v3[3] = {bottomVertices[next][0], bottomVertices[next][1], -height / 2};

        float normal[3];
        calculateNormal(v0, v1, v2, normal);

        glNormal3f(normal[0], normal[1], normal[2]);

        glVertex3f(bottomVertices[i][0], bottomVertices[i][1], -height / 2);
        glVertex3f(topVertices[i][0], topVertices[i][1], height / 2);
        glVertex3f(topVertices[next][0], topVertices[next][1], height / 2);
        glVertex3f(bottomVertices[next][0], bottomVertices[next][1], -height / 2);
    }
    glEnd();
}

