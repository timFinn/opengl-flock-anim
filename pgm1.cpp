#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

#include "my_setup_3D_18.h"

#define canvas_Width 640
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

void updatePosition()
{
    //Code logic for taking value pass in using pointer and update the position
    //values of the flock members every 75 - 100ms
    ++x_offset;
    glutPostRedisplay();
}

void kbHandler(unsigned char key, int x, int y)
{
    std::cout << key << std::endl;
    // switch(key)
    // {
    //     case 32:
    //         printf("Start flying");
    //         break;
    //     case 88:
    //         exit(0);
    //         break;
    //     default:
    //         break;
    // }

}

void display_func()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGoose(190 + x_offset, (canvas_Height / 2));
    drawGoose(50 + x_offset, (canvas_Height / 2) + 75);
    drawGoose(50 + x_offset, (canvas_Height / 2) - 75);

    //updatePosition();

    glFlush();
}

void timer_func(int ID)
{
    ++x_offset;
    display_func();
    glutTimerFunc(75, timer_func, 1);
}

void initRendering()
{
    glClearColor(0.0, 1.0, 1.0, 1.0);
    glLineWidth(2.0);
}

int main (int argc, char ** argv)
{
    x_offset = 0;

    glutInit(&argc, argv);
    glutKeyboardFunc(kbHandler);
    my_setup(canvas_Width, canvas_Height, canvas_Name);
    initRendering();
    
    glutTimerFunc(75, timer_func, 1);

    glutDisplayFunc(display_func);
    

    glutMainLoop();
    return 0;
}
