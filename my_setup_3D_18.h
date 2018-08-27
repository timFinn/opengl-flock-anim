/****

****/

void my_3d_projection(int width, int height)
{
    GLfloat width_bound, height_bound;

    width_bound = width; height_bound = height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, width_bound, 0.0, height_bound, 0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

#define STRT_X_POS 25
#define STRT_Y_POS 25

void my_setup(int width, int height, char *window_name_str)
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);

    glutInitWindowPosition(STRT_X_POS, STRT_Y_POS);

    glutCreateWindow(window_name_str);

    glutReshapeFunc(my_3d_projection);
}
