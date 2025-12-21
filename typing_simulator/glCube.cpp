#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glut.h>

GLfloat angle = 0.0f;

void displayCube() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5,0,0,0,0,1,0);
    glRotatef(angle,1.0f,1.0f,1.0f);

    glColor3f(0.0f, 0.5f, 1.0f);
    glutWireCube(1.0f);

    glutSwapBuffers();

    angle += 0.5f;
    if(angle > 360.0f) angle -= 360.0f;
}

void reshapeCube(int width, int height) {
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
}

void keyboardCube(unsigned char key, int x, int y) {
    if (key == 27 || key == 13) { // Esc or Enter
        glutLeaveMainLoop();     // exit GLUT loop
    }
}

void startCube() {
    int argc = 1;
    char* argv[1] = {(char*)"CubeApp"};
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL CUBE++");

    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(displayCube);
    glutReshapeFunc(reshapeCube);
    glutIdleFunc(displayCube);
    glutKeyboardFunc(keyboardCube);

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    glutMainLoop();
}
