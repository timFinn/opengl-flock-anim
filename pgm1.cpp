/****
	CS 445 Program 1
	Written by Timothy Finnegan

	Software Architecture Statement
	
	This application is designed to draw a flock of "geese" and move them across
	the canvas. That is achieved by using draw calls to GL_LINE_LOOP for the "geese"
	and GL_TRIANGLE_FAN for the clouds. Animated movement is achieved by incrementing
	an offset variable in the display function. The display function is called using
	the OpenGL timer handler. The timer is called after the first keyboard event and
	called again at the end of the display function.

	Drawing of the "geese" and the clouds has been made modular by encapsulating the
	drawing logic into respective functions. The functions are called in the display
	function and given the necessary parameters as well as the x-axis offset variable.

****/

#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <cmath>

#include "my_setup_3D_18.h"

#define canvas_Width 480
#define canvas_Height 480
#define canvas_Name "CS 445 - Program 1"
#define PI 3.14159265359

int x_offset;
bool start_flag;

void drawGoose(int init_x, int init_y)
{
    glBegin(GL_LINE_LOOP);
      glColor3f(0.0, 0.0, 0.0);
      glVertex2i(init_x, init_y);
      glVertex2i(init_x + 60, init_y); // head
      glVertex2i(init_x, init_y);
      glVertex2i(init_x - 40, init_y + 40); // top wing
      glVertex2i(init_x, init_y);
      glVertex2i(init_x - 40, init_y - 40); // bottom wing
      glVertex2i(init_x, init_y);
      glVertex2i(init_x - 40, init_y); // tail
    glEnd();
}

void drawGooseFlap(int init_x, int init_y)
{
	glBegin(GL_LINE_LOOP);
      glColor3f(0.0, 0.0, 0.0);
      glVertex2i(init_x, init_y);
      glVertex2i(init_x + 60, init_y); // head
      glVertex2i(init_x, init_y);
      glVertex2i(init_x, init_y + 40); // top wing
      glVertex2i(init_x, init_y);
      glVertex2i(init_x, init_y - 40); // bottom wing
      glVertex2i(init_x, init_y);
      glVertex2i(init_x - 40, init_y); // tail
    glEnd();
}

void drawCloud(float x, float y, float radius)
{
	int triangleResolution = 32;

	// Cloud component 1
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.8, 0.8, 0.8);
      glVertex2f(x, y);
      for (int i = 0; i < triangleResolution + 1; i++)
      {
      	glVertex2f(
      		(x + (radius * cos(i * (2*PI) / triangleResolution))), 
      		(y + (radius * sin(i * (2*PI) / triangleResolution)))
      		);
      }
    glEnd();

    x += 20;

    // Cloud component 2
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.8, 0.8, 0.8);
      glVertex2f(x, y);
      for (int i = 0; i < triangleResolution + 1; i++)
      {
      	glVertex2f(
      		(x + (radius * cos(i * (2*PI) / triangleResolution))), 
      		(y + (radius * sin(i * (2*PI) / triangleResolution)))
      		);
      }
    glEnd();

    x += 20;

    // Cloud component 3
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.8, 0.8, 0.8);
      glVertex2f(x, y);
      for (int i = 0; i < triangleResolution + 1; i++)
      {
      	glVertex2f(
      		(x + (radius * cos(i * (2*PI) / triangleResolution))), 
      		(y + (radius * sin(i * (2*PI) / triangleResolution)))
      		);
      }
    glEnd();

    x -= 10;
    y += 20;

    // Cloud component 4
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.8, 0.8, 0.8);
      glVertex2f(x, y);
      for (int i = 0; i < triangleResolution + 1; i++)
      {
      	glVertex2f(
      		(x + (radius * cos(i * (2*PI) / triangleResolution))), 
      		(y + (radius * sin(i * (2*PI) / triangleResolution)))
      		);
      }
    glEnd();

    x -= 20;

    // Cloud component 5
    glBegin(GL_TRIANGLE_FAN);
      glColor3f(0.8, 0.8, 0.8);
      glVertex2f(x, y);
      for (int i = 0; i < triangleResolution + 1; i++)
      {
      	glVertex2f(
      		(x + (radius * cos(i * (2*PI) / triangleResolution))), 
      		(y + (radius * sin(i * (2*PI) / triangleResolution)))
      		);
      }
    glEnd();
}

void display_func()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGoose(100 + x_offset, canvas_Height - 50);
    drawGoose(100 + x_offset, canvas_Height  - 150);
    drawGoose(240 + x_offset, canvas_Height -75);

    drawCloud((canvas_Width - 50) - (x_offset/2), 100, 20);
    drawCloud((canvas_Width - 150) - (x_offset/3), 200, 20);
    drawCloud((canvas_Width - 175) - (x_offset/3), 50, 20);
    drawCloud((canvas_Width - 200) - (x_offset/2), 150, 20);

    glFlush();
}

void display_func2()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawGooseFlap(100 + x_offset, canvas_Height - 50);
    drawGooseFlap(100 + x_offset, canvas_Height  - 150);
    drawGooseFlap(240 + x_offset, canvas_Height -75);

    drawCloud((canvas_Width - 50) - (x_offset/2), 100, 20);
    drawCloud((canvas_Width - 150) - (x_offset/3), 200, 20);
    drawCloud((canvas_Width - 175) - (x_offset/3), 50, 20);
    drawCloud((canvas_Width - 200) - (x_offset/2), 150, 20);

    glFlush();
}

void timer_func(int ID)
{
    x_offset += 10;

    if (x_offset == 50 || x_offset == 150 || x_offset == 250 || x_offset == 350)
    {
    	display_func2();
    }
    else
    {
    	display_func();
    }
    
    glutTimerFunc(100, timer_func, 1);
}

void kbHandler(unsigned char key, int x, int y)
{    
	if (start_flag == false)
	{
		glutTimerFunc(100, timer_func, 1);
		start_flag = true;
	}    
    else
    {
    	if (key == 'r')
    	{
    		x_offset = 0;
    	}    	
    }
}

void initRendering()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glLineWidth(1.0);
}

int main (int argc, char ** argv)
{
    x_offset = 0;
    start_flag = false;

    glutInit(&argc, argv);    
    my_setup(canvas_Width, canvas_Height, canvas_Name);
    initRendering();   

    glutDisplayFunc(display_func);
    glutKeyboardFunc(kbHandler);

    std::cout << "Any Key Click Will Start." << std::endl;
    std::cout << "Press R to reset the flock." << std::endl;

    glutMainLoop();

    return 0;
}
