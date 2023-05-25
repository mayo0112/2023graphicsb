#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0,z=0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    {
    glVertex2f(-0.39, -0.13);
    glVertex2f(-0.33, 0.00);
    glVertex2f(-0.13, 0.03);
    glVertex2f(0.13, 0.03);
    glVertex2f(0.27, 0.03);
    glVertex2f(0.41, -0.02);
    glVertex2f(0.47, -0.17);
    glVertex2f(0.47, -0.33);
    glVertex2f(0.38, -0.40);
    glVertex2f(0.06, -0.42);
    glVertex2f(-0.07, -0.42);
    glVertex2f(-0.27, -0.39);
    glVertex2f(-0.37, -0.13);
    }
    glEnd();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{
    float X=(x-150)/150.0;
    float Y=-(y-150)/150.0;
    if(state==GLUT_DOWN)
    {
        printf("    glVertex2f(%.2f, %.2f);\n",X,Y);
    }
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("GLUT Shapes");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();
}
