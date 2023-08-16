#include <GL/glut.h>
#include <stdio.h>

void drawLine(int x1, int y1, int x2, int y2)
{
    int dx, dy, d, incE, incNE, x, y;
    dx = x2 - x1;
    dy = y2 - y1;

    if(dy <= dx)
    {
        d = dy - (dx/2);
        x = x1, y = y1;
        glBegin(GL_POINTS);
        glVertex2i(x, y);

        while (x < x2)
        {
            x = x+1;

            if (d < 0)
            {
                d = d + dy;
            }

            else
            {
                d = d + dy - dx;
                y = y+1;
            }

            glVertex2i(x, y);
        }

        glEnd();
        glFlush();
    }

    else if(dx <= dy)
    {
        d = dx - (dy/2);
        x = x1, y = y1;
        glBegin(GL_POINTS);
        glVertex2i(x, y);

        while (y < y2)
        {
            y = y+1;

            if (d < 0)
            {
                d = d + dx;
            }

            else
            {
                d = d + dx - dy;
                x = x+1;
            }

            glVertex2i(x, y);
        }
        glEnd();
        glFlush();
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x1,y1,x2,y2;
    printf("X1 : ");
    scanf("%d",&x1);
    printf("Y1 : ");
    scanf("%d",&y1);
    printf("X2 : ");
    scanf("%d",&x2);
    printf("Y2 : ");
    scanf("%d",&y2);
    drawLine(x1, y1, x2, y2);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Line Drawing Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    gluOrtho2D(0, 400, 0, 400);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
