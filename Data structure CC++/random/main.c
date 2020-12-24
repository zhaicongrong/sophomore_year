#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//随机生成0或者1
int main()
{
    srand((unsigned)time(NULL));//srand()就是给rand()提供种子seed
    printf("%d\n", 100);
    //100次随机生成0或者1
    for (int i =0; i < 100; i++)
    {
        int num = rand()%2;//对2取余得到就是0或者1

        printf("%d ",num);
    }
    return 0;
}
