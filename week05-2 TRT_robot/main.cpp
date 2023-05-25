#include <GL/glut.h>
float angle = 0;
void myCube()
{
    glPushMatrix();
    glScaled( 0.5, 0.2, 0.2); ///調大小
    glutSolidCube(1); ///正方塊
    glPopMatrix();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景
    glColor3f(1, 1, 1); ///白色的
    glutSolidCube(1);   ///身體

    glPushMatrix();
        glTranslatef(0.5, 0.5, 0); ///3把整個東西掛在右上角
        glRotatef(angle, 0, 0, 1);   ///2轉動他
        glTranslatef(0.25, 0, 0); ///1往右移動0.25把旋轉中心,放到世界中心
        glColor3f(0, 1, 0); ///綠色的
        myCube(); ///改函式
    glPopMatrix();
    glPushMatrix();
        glTranslatef(-0.5, 0.5, 0); ///掛在左上角
        glRotatef(angle, 0, 0, 1);   ///2轉動他
        glTranslatef(0.25, 0, 0); ///1往右移動0.25把旋轉中心,放到世界中心
        glColor3f(0, 1, 0); ///綠色的
        myCube(); ///改函式
    glPopMatrix();

    glutSwapBuffers();
    angle++; ///step02-1 把角度++
}

int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///有空idle時,就重畫畫面
    glutMainLoop();
}
