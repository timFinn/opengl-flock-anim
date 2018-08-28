#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#include "my_setup_3D_18.h"

#define canvas_Width 480
#define canvas_Height 480
#define canvas_Name "CS 445 - Program 1"

int x_offset;

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

void drawClouds()
{
    
}

void display_func()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGoose(100 + x_offset, canvas_Height - 50);
    drawGoose(100 + x_offset, canvas_Height  - 150);
    drawGoose(240 + x_offset, canvas_Height -75);

    glFlush();
}

void timer_func(int ID)
{
    x_offset += 10;
    display_func();
    glutTimerFunc(100, timer_func, 1);
}

void kbHandler(unsigned char key, int x, int y)
{    
    glutTimerFunc(100, timer_func, 1);
}

void initRendering()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLineWidth(1.0);
}

int main (int argc, char ** argv)
{
    x_offset = 0;

    glutInit(&argc, argv);    
    my_setup(canvas_Width, canvas_Height, canvas_Name);
    initRendering();   

    glutDisplayFunc(display_func);
    glutKeyboardFunc(kbHandler);

    std::cout << "Any Key Click Will Start." << std::endl;       

    glutMainLoop();

    return 0;
}
