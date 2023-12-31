#include <GL/glut.h>
float translateX = 0.0f, translateY = 0.0f, translateZ = -5.0f;
float rotateX = 0.0f, rotateY = 0.0f, rotateZ = 0.0f;
float scaleX = 1.0f, scaleY = 1.0f, scaleZ = 1.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translateX, translateY, translateZ);
    glRotatef(rotateX, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateY, 0.0f, 1.0f, 0.0f);
    glRotatef(rotateZ, 0.0f, 0.0f, 1.0f);
    glScalef(scaleX, scaleY, scaleZ);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
    //front
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    //back
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    //top
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    //bottom
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    //right
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    //left
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    glEnd();
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)width / (float)height, 0.1f, 100.0f);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        translateY += 0.1f;
        break;
    case 's':
        translateY -= 0.1f;
        break;
    case 'a':
        translateX -= 0.1f;
        break;
    case 'd':
        translateX += 0.1f;
        break;
    case 'q':
        translateZ += 0.1f;
        break;
    case 'e':
        translateZ -= 0.1f;
        break;
    case 'i':
        rotateX += 5.0f;
        break;
    case 'k':
        rotateX -= 5.0f;
        break;
    case 'j':
        rotateY += 5.0f;
        break;
    case 'l':
        rotateY -= 5.0f;
        break;
    case 'u':
        rotateZ += 5.0f;
        break;
    case 'o':
        rotateZ -= 5.0f;
        break;
    case 'x':
        scaleX += 0.1f;
        break;
    case 'X':
        scaleX -= 0.1f;
        break;
    case 'y':
        scaleY += 0.1f;
        break;
    case 'Y':
        scaleY -= 0.1f;
        break;
    case 'z':
        scaleZ += 0.1f;
        break;
    case 'Z':
        scaleZ -= 0.1f;
        break;
    case 27:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Transformations");
    glEnable(GL_DEPTH_TEST);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

    return 0;
}

