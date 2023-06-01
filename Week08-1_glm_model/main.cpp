#include <GL/glut.h>
#include "glm.h" ///��source.zip�̪� glm.h��b�P�ؿ���
GLMmodel *pmodel = NULL; ///�ҫ������СA�@�}�lNULL�Ū�
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(pmodel==NULL)
    {
        pmodel=glmReadOBJ("F-16.obj"); ///�ɦW�ӧA���ɦW��
        glmUnitize(pmodel); ///�Y��Unit���j�p(-1...+1)
    }
    glmDraw(pmodel,GLM_SMOOTH | GLM_MATERIAL);

    ///glutSolidTeapot(0.3);
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week08");

    glutDisplayFunc(display);
    glutMainLoop();
}
