#include <GL/glut.h>
float angle=0, newAngle=0, oldAngle=0; ///�s���� �¨���
float oldX=0; ///��X�y��
void timer(int t){
    if(t<100) glutTimerFunc(30,timer,t+1);
    float alpha = t/100.0; ///alpha�b0.0~1.0����
    angle = alpha*newAngle + (1-alpha)*oldAngle;
    glutPostRedisplay(); ///���e�e��
}
void keyboard(unsigned char key,int x,int y){
    glutTimerFunc(0,timer,0);
}
void mouse(int button,int state,int x,int y){
    if(state==GLUT_DOWN) oldAngle=angle;
    if(state==GLUT_UP) newAngle=angle;
    oldX = x;
    glutPostRedisplay();
}
void motion(int x,int y){
    angle += x-oldX;
    oldX = x;
    glutPostRedisplay(); ///��s�e��
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle,0,0,1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc,char** argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);
    ///glutTimerFunc(1000,timer,0);
    glutMainLoop();
}
