#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void translate(float x, float y, float z){
    GLfloat matrix[16] = {1, 0, 0, 0,
                          0, 1, 0, 0,
                          0, 0, 1, 0,
                          x, y, z, 1};
    glMultMatrixf(matrix);
}

void rotatex(float theta){
    GLfloat matrix[16] = {1, 0, 0, 0,
                          0, 1, 0, 0,
                          0, 0, cosf(theta), sinf(theta),
                          0, 0, -sinf(theta), cosf(theta)};
    glMultMatrixf(matrix);
}

void rotatey(float theta){
    GLfloat matrix[16] = {cosf(theta), 0, -sinf(theta), 0,
                          0,           1, 0,            0,
                          sinf(theta), 0, cosf(theta),  0,
                          0,           0, 0,            1};
    glMultMatrixf(matrix);
}

void rotatez(float theta){
    GLfloat matrix[16] = {cosf(theta),  sinf(theta), 0, 0,
                          -sinf(theta), cosf(theta), 0, 0,
                          0,            0,           1, 0,
                          0,            0,           0, 1};
    glMultMatrixf(matrix);
}

void scale(float x, float y, float z){
    GLfloat matrix[16] = {x, 0, 0, 0,
                          0, y, 0, 0,
                          0, 0, z, 0,
                          0, 0, 0, 1};
    glMultMatrixf(matrix);  
}

void orthogonal(float left, float right, float bottom, float top, float near, float far){
    float scale_x  =  2.0f/(right - left);
    float scale_y  =  2.0f/(top - bottom);
    float scale_z  = -2.0f/(far - near);
    float offset_x = -(right+left)/(right-left);
    float offset_y = -(top+bottom)/(top-bottom);
    float offset_z = -(far+near)  /(far-near);

    float matrix[16] = {scale_x,  0.0f,     0.0f,     0.0f,
                        0.0f,     scale_y,  0.0f,     0.0f,
                        0.0f,     0.0f,     scale_z,  0.0f,
                        offset_x, offset_y, offset_z, 1.0f};

    glMultMatrixf(matrix);
}

void perspective(float left, float right, float bottom, float top, float near, float far){
    //https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix.html
    float scale_x  =  2.0f*near/(right - left);
    float scale_y  =  2.0f*near/(top - bottom);
    float scale_z  = -2.0f*far*near/(far - near);
    float offset_x = (right+left)/(right-left);
    float offset_y = (top+bottom)/(top-bottom);
    float offset_z = -(far+near)  /(far-near);

    float matrix[16] = {scale_x,  0.0f,     0.0f,      0.0f,
                        0.0f,     scale_y,  0.0f,      0.0f,
                        offset_x, offset_y, offset_z, -1.0f,
                        0.0f,     0.0f,     scale_z,   0.0f};

    glMultMatrixf(matrix);   
}

pair<vector<int>, vector<int>> DDA(int x1, int y1, int z1, int x2, int y2, int z2){
    int length = abs(x1-x2)>=abs(y1-y2) ? abs(x1-x2) : abs(y1-y2);
    float delta_x = static_cast<float>(x2-x1)/length;
    float delta_y = static_cast<float>(y2-y1)/length;
    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);
    vector<int> xs(length+1);
    vector<int> ys(length+1);
    for (int i=0; i<=length; i++){
        xs[i] = round(x);
        ys[i] = round(y);
        x += delta_x;
        y += delta_y;
    }
    return {xs, ys};
}

pair<vector<int>, vector<int>> bresenham(int x1, int y1, int z1, int x2, int y2, int z2){
    int delta_x = x2-x1;
    int delta_y = y2-y1;
    float m = static_cast<float>(delta_y)/delta_x;
    float e = m-0.5;
    vector<int> xs(delta_x+1);
    vector<int> ys(delta_x+1);
    for (int i=0; i<=delta_x; i++){
        xs[i] = x1;
        ys[i] = y1;
        while(e>0){
            y1 += 1;
            e  -= 1;
        }
        x1 += 1;
        e  += m;
    }
    return {xs, ys};
}