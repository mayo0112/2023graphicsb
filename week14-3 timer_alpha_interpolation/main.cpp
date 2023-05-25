#include <GL/glut.h>
float angle=0, newAngle=0, oldAngle=0; ///新角度 舊角度
float oldX=0; ///舊X座標
void timer(int t){
    if(t<100) glutTimerFunc(30,timer,t+1);
    float alpha = t/100.0; ///alpha在0.0~1.0之間
    angle = alpha*newAngle + (1-alpha)*oldAngle;
    glutPostRedisplay(); ///重畫畫面
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
    glutPostRedisplay(); ///更新畫面
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
