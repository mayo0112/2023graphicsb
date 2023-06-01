#include <stdio.h>///�n�ɮת�Input/Output
#include <GL/glut.h>
#include "glm.h"///�A��glm.cpp �b���� Add files �[�i�h
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;

int show[4] = {1,1,1,1};///week14_step03-1 ���q�X��
int ID = 3;///week14_step03-1 �]�w���` ID 0:�Y 1:���� 2:�W���u 3:�U���u
float teapotX=0,teapotY=0;
float angle[20]={};///Week15-3_step03-1
///float angle=0, angle2=0, angle3=0;///week14_step03-2
FILE * fout = NULL;
FILE * fin = NULL;

void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') ID = 0; ///week14_step03-1 ///show[0] = ! show[0];
    if(key=='1') ID = 1; ///week14_step03-1 ///show[1] = ! show[1];
    if(key=='2') ID = 2; ///week14_step03-1 ///show[2] = ! show[2];
    if(key=='3') ID = 3; ///week14_step03-1 ///show[3] = ! show[3];
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(head==NULL)
    {
        head = glmReadOBJ("model/head.obj");
        body = glmReadOBJ("model/body.obj");
        uparmR = glmReadOBJ("model/uparmR.obj");
        lowarmR = glmReadOBJ("model/lowarmR.obj");
        ///glmUnitize(head);
    }
    glPushMatrix();
        glScalef(0.3,0.3,0.3);
        glPushMatrix();
            ///glTranslatef(teapotX,teapotY,0);

            if(ID==0) glColor3f(1,0,0); ///week14_step03-1 ����
            else glColor3f(1,1,1); ///week14_step03-1 �զ�
            if(show[0]) glmDraw(head,GLM_MATERIAL);
        glPopMatrix();

        if(ID==1) glColor3f(1,0,0); ///week14_step03-1 ����
        else glColor3f(1,1,1); ///week14_step03-1 �զ�
        if(show[1]) glmDraw(body,GLM_MATERIAL);

        glPushMatrix(); ///week14_step03_2
            ///glTranslatef(teapotX, teapotY, 0); ///week14_step03_2 �n�]�w TRT
            glTranslatef(-1.360000, +0.360000, 0); ///week14_step03_2
            glRotatef(angle[2], 0, 0, 1); ///week14_step03_2
            glTranslatef(1.360000, -0.360000, 0); ///week14_step03_2

            if(ID==2) glColor3f(1,0,0); ///week14_step03-1 ����
            else glColor3f(1,1,1); ///week14_step03-1 �զ�
            if(show[2]) glmDraw(uparmR,GLM_MATERIAL);

            glPushMatrix();  ///week14_step03_2
                ///glTranslatef(teapotX, teapotY, 0); ///week14_step03_2 �n�]�w TRT
                glTranslatef(-1.959999, +0.080000, 0);
                glRotatef(angle[3], 0, 0, 1);
                glTranslatef(1.959999, -0.080000, 0);

                if(ID==3) glColor3f(1,0,0); ///week14_step03-1 ����
                else glColor3f(1,1,1); ///week14_step03-1 �զ�
                if(show[3]) glmDraw(lowarmR,GLM_MATERIAL);

            glPopMatrix();  ///week14_step03_2

        glPopMatrix(); ///week14_step03_2

    glPopMatrix();

    glColor3f(0,1,0);///week14_step03_2 ��⪺
    glutSolidTeapot(0.02);///�]�p�����@�������I
    glutSwapBuffers();
}
int oldX=0, oldY=0;
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN)
    {
        oldX = x;
        oldY = y;
    }
}
void motion(int x,int y)
{
    teapotX += (x - oldX)/150.0*3;
    teapotY -= (y - oldY)/150.0*3;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY); ///week14_step03_2
    angle[ID] += x-oldX; ///week15_step3-1
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}
