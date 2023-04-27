#include <windows.h>
#include <GL/glut.h>
int main(int argc,char**argv)
{
    ///絕對路徑
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav",NULL,SND_ASYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav",NULL,SND_ASYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav",NULL,SND_ASYNC);

    ///相對路徑
    PlaySound("do-re-mi/do.wav",NULL,SND_ASYNC);
    printf("Hello World\n");
}
