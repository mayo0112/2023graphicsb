#include <windows.h>///step01-2 �n��b�Ĥ@��
#include <stdio.h>

int main()
{///Setting Compiler,Linker�G�y�G�ݭn winmm
    ///������| Absolute Path
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\do.wav",NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\re.wav",NULL,SND_SYNC);
    ///PlaySound("C:\\Users\\Administrator\\Desktop\\do-re-mi\\mi.wav",NULL,SND_SYNC);

    ///�ؿ����׽u�i�H�� ��Ӥϱ׽u\\�A�Ϊ̤@�ӱ׽u/
    PlaySound("do-re-mi/do.wav",NULL,SND_SYNC);
    ///�۹���| Relative Path

    printf("Hello World");
}
