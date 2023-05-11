#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * uparmL = NULL;
GLMmodel * lowarmR = NULL;
GLMmodel * lowarmL = NULL;
GLMmodel * uplegR = NULL;
GLMmodel * uplegL = NULL;
GLMmodel * lowlegR = NULL;
GLMmodel * lowlegL = NULL;
int show[10] = {0,1,2,3,4,5,6,7,8,9};
void keyboard(unsigned char key,int x,int y){
    if(key=='0') show[0] = !show[0];
    if(key=='1') show[1] = !show[1];
    if(key=='2') show[2] = !show[2];
    if(key=='3') show[3] = !show[3];
    if(key=='4') show[4] = !show[4];
    if(key=='5') show[5] = !show[5];
    if(key=='6') show[6] = !show[6];
    if(key=='7') show[7] = !show[7];
    if(key=='8') show[8] = !show[8];
    if(key=='9') show[9] = !show[9];
    glutPostRedisplay();
}
float teapotX=0,teapotY=0;
FILE * fout = NULL; ///step02-1
FILE * fin = NULL; ///step02-1
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glScalef(0.2,0.2,0.2);
    if(head==NULL){
        body=glmReadOBJ("model/body.obj");
        head=glmReadOBJ("model/head.obj");
        lowarmR=glmReadOBJ("model/lowarmR.obj");
        lowarmL=glmReadOBJ("model/lowarmL.obj");
        uparmL=glmReadOBJ("model/uparmL.obj");
        uparmR=glmReadOBJ("model/uparmR.obj");
        lowlegL=glmReadOBJ("model/lowlegL.obj");
        lowlegR=glmReadOBJ("model/lowlegR.obj");
        uplegL=glmReadOBJ("model/uplegL.obj");
        uplegR=glmReadOBJ("model/uplegR.obj");
        }
        if(show[0]) glmDraw(head, GLM_MATERIAL);
        if(show[1]) glmDraw(body, GLM_MATERIAL);
        if(show[2]) glmDraw(lowarmR, GLM_MATERIAL);
        if(show[3]) glmDraw(lowarmL, GLM_MATERIAL);
        if(show[4]) glmDraw(uparmL, GLM_MATERIAL);
        if(show[5]) glmDraw(uparmR, GLM_MATERIAL);
        if(show[6]) glmDraw(uplegR, GLM_MATERIAL);
        if(show[7]) glmDraw(uplegL, GLM_MATERIAL);
        if(show[8]) glmDraw(lowlegR, GLM_MATERIAL);
        if(show[9]) glmDraw(lowlegL, GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(teapotX,teapotY,0);
            if(show[0]) glmDraw(head,GLM_MATERIAL);
        glPopMatrix();
        if(show[1]) glmDraw(body,GLM_MATERIAL);
        if(show[2]) glmDraw(uparmL,GLM_MATERIAL);
        if(show[3]) glmDraw(lowarmL,GLM_MATERIAL);
        glPopMatrix();
        glutSwapBuffers();
}
int oldX=0, oldY=0;
void mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN){///如果mouse按下去
      oldX=x;
      oldY=y;
    }
}
void motion(int x,int y){
    teapotX += (x-oldX)/150.0;
    teapotY += (y-oldY)/150.0;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
}
/* void keyboard(unsigned char key, int x,int y)
{
    if(fin==NULL){
        fclose(fout);
        fin = fopen("file4.txt","r");
    }
    fscanf(fout,"%f%f",&teapotX,&teapotY);
    display();
} */
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week13");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMainLoop();
}
