#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {1, 1, 1, 1}; ///用 show[i] 來決定要不要顯示
int ID = 0; ///0:頭 1身體 2上手臂 3下手臂
void keyboard(unsigned char key, int x, int y){
    if(key=='0') ID = 0; ///week14_step02-2
    if(key=='1') ID = 1; ///week14_step02-2
    if(key=='2') ID = 2; ///week14_step02-2
    if(key=='3') ID = 3; ///week14_step02-2
    //if(key=='0') show[0] = !show[0];/// week13 step03-1
    //if(key=='1') show[1] = !show[1];/// week13 step03-1
    //if(key=='2') show[2] = !show[2];/// week13 step03-1
    //if(key=='3') show[3] = !show[3];/// week13 step03-1
    glutPostRedisplay();
}   ///原來的keyboard先註解、不要用
FILE * fout = NULL;     ///一開始檔案沒有開, NULL
FILE * fin = NULL;      ///要讀檔用的指標一開始也是 NULL
float teapotX=0, teapotY=0;         ///看移動值
float angle=0, angle2=0, angle3=0;  ///擺動作
void display()

{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.3, 0.3, 0.3);
        if(body==NULL){
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");
            uparmR = glmReadOBJ("model/uparmR.obj");
            lowarmR = glmReadOBJ("model/lowarmR.obj");
            ///glmUnitize(body);
        }
        if(ID==0) glColor3f(1,0,0);     ///選定的,設紅色
        else glColor3f(1,1,1);          ///沒選定,設白色
        if(show[0]) glmDraw(head, GLM_MATERIAL);///Week13 step03-1

        if(ID==1) glColor3f(1,0,0);     ///選定的,設紅色
        else glColor3f(1,1,1);          ///沒選定,設白色
        if(show[1]) glmDraw(body, GLM_MATERIAL);
        glPushMatrix();
            glTranslatef(-1.200000, +0.453333, 0); ///反過來
            glRotatef(angle, 0, 0, 1);
            glTranslatef(1.200000, -0.453333, 0);

            if(ID==2) glColor3f(1,0,0); ///選定的,設紅色
            else glColor3f(1,1,1);      ///沒選定,設白色
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);
            glPushMatrix();
                glTranslatef(-1.959999, +0.113333, 0);
                glRotatef(angle, 0, 0, 1);
                glTranslatef(1.959999, -0.113333, 0);

            if(ID==3) glColor3f(1,0,0); ///選定的,設紅色
            else glColor3f(1,1,1);      ///沒選定,設白色
            if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glColor3f(0, 1, 0);     ///放個小茶壼在正中心當成參考點
    glutSolidTeapot( 0.02 );///放個小茶壼在正中心當成參考點
    glutSwapBuffers();
}
int oldX = 0, oldY = 0; ///Week13 step03-2
void motion(int x, int y){
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f, %f, 0);\n", teapotX, teapotY);
    glutPostRedisplay();
}
void mouse(int button, int state, int x, int y){
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
        angle = x;
    }
    display();
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard); ///keyboard開檔、讀檔
    glutMainLoop();
}
