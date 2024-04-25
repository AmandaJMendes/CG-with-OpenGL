#include <GL/glut.h>
#include <cmath>

void display() {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Set line color to white

    glLoadIdentity();

    glBegin(GL_LINES);
    glVertex2f(0, 0.30); // First endpoint
    glVertex2f(90, 0.0);  // Second endpoint
    glEnd();

    glFlush(); // Ensure all OpenGL commands are executed
}
void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float left = -100.0f;
    float right = 100.0f;
    float bottom = -100.0f;
    float top = 100.0f;
    float nearVal = -1.0f;
    float farVal = 1.0f;
    float projMatrix[16] = {
        2.0f / (right - left), 0.0f, 0.0f, 0,
        0.0f, 2.0f / (top - bottom), 0.0f, 0,
        0.0f, 0.0f, -2.0f / (farVal - nearVal), 0,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(projMatrix);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode
    glutInitWindowSize(800, 800); // Set window size
    glutCreateWindow("Manual Projection"); // Create window with title
    glClearColor(0.0, 0.0, 0.0, 0.0); // Set clear color to black
    glutDisplayFunc(display); // Set display callback function
    glutReshapeFunc(reshape);
    glutMainLoop(); // Enter GLUT main loop
    return 0;
}
