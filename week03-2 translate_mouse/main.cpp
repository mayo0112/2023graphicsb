#include <GL/glut.h>
float X=0,Y=0,z=0; ///使用global變數
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(X,Y,z); ///照xyz移動
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
void mouse(int button,int state,int x,int y)
{        ///左中右鍵  按下/放開  小x  小y
    X=(x-150)/150.0;
    Y=-(y-150)/150.0;
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03");
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
	glutMainLoop();
}
