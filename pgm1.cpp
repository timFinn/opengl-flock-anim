#include <GL/glut.h>
#include <stdio.h>

#include "my_setup_3D_18.h"

#define canvas_Width 640
#define canvas_Height 480
#define canvas_Name "CS 445 - Program 1"

void drawGoose(int init_x, int init_y)
{
    glBegin(GL_LINE_LOOP);
      glColor3f(0.0, 0.0, 0.0);
      glVertex2i(init_x, init_y);
      glVertex2i(init_x + 60, init_y);
      glVertex2i(init_x, init_y);
      glVertex2i(init_x - 40, init_y + 40);
      glVertex2i(init_x, init_y);
      glVertex2i(init_x - 40, init_y - 40);
      glVertex2i(init_x, init_y);
      glVertex2i(init_x - 40, init_y);
    glEnd();
}

void updatePosition()
{
    //Code logic for taking value pass in using pointer and update the position
    //values of the flock members every 75 - 100ms
}

void display_func()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGoose(190, (canvas_Height / 2));
    drawGoose(50, (canvas_Height / 2) + 75);
    drawGoose(50, (canvas_Height / 2) - 75);

    glFlush();
}

void initRendering()
{
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glLineWidth(2.0);
}

void kbHandler(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 32:
            printf("Start flying");
            break;
        case 88:
            exit(0);
            break;
        default:
            break;
    }

}

int main (int argc, char ** argv)
{
    glutInit(&argc, argv);

    my_setup(canvas_Width, canvas_Height, canvas_Name);
    initRendering();

    glutDisplayFunc(display_func);
    glutKeyboardFunc(kbHandler);

    glutMainLoop();
    return 0;
}
