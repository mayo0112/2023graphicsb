#include <opencv/highgui.h>
int main()
{
    IplImage*img=cvLoadImage("1.png");///���ɭn��b�ޭ��������ؿ���
    cvShowImage("week07",img);
    cvWaitKey(0);///�e�����n�{�h�A���@�U�ץ��N���~��
}
