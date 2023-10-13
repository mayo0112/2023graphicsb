#include <GL/glut.h>
float angle=0;
void myCube()
{
    glPushMatrix();///²�Ƶ{��
        glScalef(0.5,0.2,0.2);///�վ�j�p
        glutSolidCube(1);///�����
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);///�զ�
    glutSolidCube(1);///����

    glPushMatrix();
        glTranslatef(0.5,0.5,0);///��b�k�W��
        glRotatef(angle,0,0,1);///�०
        glTranslatef(0.25,0,0);///���k����0.25�����`�b������
        glColor3f(0,1,0);///���
        myCube();///����
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,0.5,0);///��b���W��
        glRotatef(angle,0,0,1);///�०
        glTranslatef(0.25,0,0);///���k����0.25�����`�b������
        glColor3f(0,1,0);///���
        myCube();///����
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week05");

    glutDisplayFunc(display);
    glutIdleFunc(display);///���e�e��

    glutMainLoop();
}
