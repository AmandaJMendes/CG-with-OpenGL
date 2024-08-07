#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

void translate(float x, float y, float z){
    // Apply translation matrix
    GLfloat matrix[16] = {1, 0, 0, 0,
                          0, 1, 0, 0,
                          0, 0, 1, 0,
                          x, y, z, 1};
    glMultMatrixf(matrix);
}

void rotatex(float theta){
    // Apply matrix for rotation around the x-axis
    // theta: angle (in degrees) to rotate
    // Each row in the matrix is a column
    theta *= M_PI/180.0;
    GLfloat matrix[16] = {1, 0,       0,            0, 
                      0, cosf(theta), -sinf(theta), 0,
                      0, sinf(theta), cosf(theta),  0,
                      0, 0,           0,            1};

    glMultMatrixf(matrix);
}

void rotatey(float theta){
    // Apply matrix for rotation around the y-axis
    // theta: angle (in degrees) to rotate
    // Each row in the matrix is a column
    theta *= M_PI/180.0;
    GLfloat matrix[16] = {cosf(theta), 0, -sinf(theta), 0,
                          0,           1, 0,            0,
                          sinf(theta), 0, cosf(theta),  0,
                          0,           0, 0,            1};
    glMultMatrixf(matrix);
}

void rotatez(float theta){
    // Apply matrix for rotation around the z-axis
    // theta: angle (in degrees) to rotate
    // Each row in the matrix is a column
    theta *= M_PI/180.0;
    GLfloat matrix[16] = {cosf(theta),  sinf(theta), 0, 0,
                          -sinf(theta), cosf(theta), 0, 0,
                          0,            0,           1, 0,
                          0,            0,           0, 1};
    glMultMatrixf(matrix);
}

void scale(float x, float y, float z){
    // Apply scaling matrix
    // Each row in the matrix is a column
    GLfloat matrix[16] = {x, 0, 0, 0,
                          0, y, 0, 0,
                          0, 0, z, 0,
                          0, 0, 0, 1};
    glMultMatrixf(matrix);  
}

void orthogonal(float left, float right, float bottom, float top, float znear, float zfar){
    /* 
    Apply matrix for orthogonal projection
    - The viewport's default range is -1 to 1 on every axis.
    - We need to rescale the coordinates so that the limits of the projection fit within this range,
    - The camera is at the origin, facing the negative z-axis.
    */ 
    float scale_x  =  2.0f/(right - left);
    float scale_y  =  2.0f/(top - bottom);
    float scale_z  = -2.0f/(zfar - znear);
    float offset_x = -(right+left)/(right-left);
    float offset_y = -(top+bottom)/(top-bottom);
    float offset_z = -(zfar+znear)  /(zfar-znear);

    float matrix[16] = {scale_x,  0.0f,     0.0f,     0.0f,
                        0.0f,     scale_y,  0.0f,     0.0f,
                        0.0f,     0.0f,     scale_z,  0.0f,
                        offset_x, offset_y, offset_z, 1.0f};

    glMultMatrixf(matrix);
}

void perspective(float left, float right, float bottom, float top, float znear, float zfar){
    /* 
    Apply matrix for perspective projection

    - The viewport's default range is -1 to 1 on every axis.
    - We need to rescale the coordinates so that the limits of the projection fit within this range.
    - The camera is at the origin, facing the negative z-axis.
    - Matrix exaplanation: https://www.scratchapixel.com/lessons/3d-basic-rendering/perspective-and-orthographic-projection-matrix/building-basic-perspective-projection-matrix.html
    - Each row in the matrix is a column
    */ 
    float scale_x  =  2.0f*znear/(right - left);
    float scale_y  =  2.0f*znear/(top - bottom);
    float scale_z  = -2.0f*zfar*znear/(zfar - znear);
    float offset_x = (right+left)/(right-left);
    float offset_y = (top+bottom)/(top-bottom);
    float offset_z = -(zfar+znear)  /(zfar-znear);

    float matrix[16] = {scale_x,  0.0f,     0.0f,      0.0f,
                        0.0f,     scale_y,  0.0f,      0.0f,
                        offset_x, offset_y, offset_z, -1.0f,
                        0.0f,     0.0f,     scale_z,   0.0f};

    glMultMatrixf(matrix);   
}

void DDA(int x1, int y1, int z1, int x2, int y2, int z2){
    /*
    DDA rasterization algorithm 
    - This was based on Bicho's example
    */
    int length = std::max({abs(x1-x2), abs(y1-y2), abs(z1-z2)});

    float delta_x = static_cast<float>(x2-x1)/length;
    float delta_y = static_cast<float>(y2-y1)/length;
    float delta_z = static_cast<float>(z2-z1)/length;

    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);
    float z = static_cast<float>(z1);

    glBegin(GL_LINE_STRIP);
    for (int i=0; i<=length; i++){
        glVertex3f(round(x), round(y), round(z));
        x += delta_x;
        y += delta_y;
        z += delta_z;
    }
    glEnd();
}

void bresenham(float x1, float y1, float z1, float x2, float y2, float z2){
    /*
    Bresenhan rasterization algorithm 

    - This was based on Bicho's example
    - The same considerations in the DDA function apply here
    - This only works when 0 <= delta_y <= delta_x - OTHER CASES STILL NEED TO BE IMPLEMENTED
    */
    int delta_x = x2-x1;
    int delta_y = y2-y1;
    int delta_z = z2-z1;

    float m1, m2, base_delta;
    char highest_delta;
    
    // X has the highest delta. It is our bresenham base
    if(abs(delta_x) > abs(delta_y) && abs(delta_x) > abs(delta_z)){
        m1 = static_cast<float>(abs(delta_y))/abs(delta_x);
        m2 = static_cast<float>(abs(delta_z))/abs(delta_x);
        base_delta = abs(delta_x);
        highest_delta = 'x';
    
    // Y has the highest delta. It is our bresenham base
    } else if(abs(delta_y) > abs(delta_z)) {
        m1 = static_cast<float>(abs(delta_x))/abs(delta_y);
        m2 = static_cast<float>(abs(delta_z))/abs(delta_y);
        base_delta = abs(delta_y);
        highest_delta = 'y';
    
    // Z has the highest delta. It is our bresenham base
    } else {
        m1 = static_cast<float>(abs(delta_x))/abs(delta_z);
        m2 = static_cast<float>(abs(delta_y))/abs(delta_z);
        base_delta = abs(delta_z);
        highest_delta = 'z';
    }

    float inc_x = (delta_x > 0) ? 0.1 : (delta_x < 0) ? -0.1 : 0;
    float inc_y = (delta_y > 0) ? 0.1 : (delta_y < 0) ? -0.1 : 0;
    float inc_z = (delta_z > 0) ? 0.1 : (delta_z < 0) ? -0.1 : 0;
    float e1 = m1-0.5;
    float e2 = m2-0.5;
        
    glBegin(GL_LINE_STRIP);
    for (int i=0; i<=base_delta*10; i++){
        glVertex3f(x1, y1, z1);
        switch (highest_delta) {
            case 'x':
                while(e1>0){
                    y1 += inc_y;
                    e1  -= 1;
                }
                while(e2>0){
                    z1 += inc_z;
                    e2  -= 1;
                }
                x1 += inc_x;
            break;
            case 'y':
                while(e1>0){
                    x1 += inc_x;
                    e1  -= 1;
                }
                while(e2>0){
                    z1 += inc_z;
                    e2  -= 1;
                }
                y1 += inc_y;
            break;
            case 'z':
                while(e1>0){
                    x1 += inc_x;
                    e1  -= 1;
                }
                while(e2>0){
                    y1 += inc_y;
                    e2  -= 1;
                }
                z1 += inc_z;
            break;
        }
        
        e1 += m1;
        e2 += m2;
    }
    glEnd();
}