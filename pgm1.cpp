#include <GL/glut.h>
#include <stdio.h>
//#include <iostream>

#include "my_setup_3D_18.h"

//using namespace std;

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
    glutKeyboardFunc(kbHandler);

    glutDisplayFunc(display_func);

    glutMainLoop();
    return 0;
}
