#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//�������0����1
int main()
{
    srand((unsigned)time(NULL));//srand()���Ǹ�rand()�ṩ����seed
    printf("%d\n", 100);
    //100���������0����1
    for (int i =0; i < 100; i++)
    {
        int num = rand()%2;//��2ȡ��õ�����0����1

        printf("%d ",num);
    }
    return 0;
}
