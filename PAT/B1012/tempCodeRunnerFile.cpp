#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int N;
    scanf("%d", &N);
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0, A4 = 0;
    int count2 = 1;
    int count4 = 0;
    int first = 1;
    bool j1, j2, j3, j4, j5;
    j1 = j2 = j3 = j4 = j5 = false;
    for(int i = 0; i < N; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if((tmp % 5 == 0) && (tmp % 2 == 0))
        {
            A1 += tmp;
            j1 = true;
        }
            
        if(tmp % 5 == 1)
        {
            j2 = true;
            if(count2 % 2 == 1)
                A2 += tmp;
            else
                A2 -= tmp;
            count2++;
        }
        if(tmp % 5 == 2)
        {
             A3++;
             j3 = true;
        }
           
        if(tmp % 5 == 3)
        {
            j4 = true;
            A4 += tmp;
            count4++;
        }
        if(tmp % 5 == 4)
        {
            j5 = true;
            if(first)
                A5 = tmp;
            else
                {
                    A5 = A5 > tmp ? A5 : tmp;
                    first = 0;
                }
        }
    }
    if(j1)
        printf("%d ", A1);
    else
        printf("N ");
    if(j2)
        printf("%d ", A2);
    else
        printf("N ");
    if(j3)
        printf("%d ", A3);
    else
        printf("N ");
    if(j4)
        printf("%.1f ", A4/count4);
    else
        printf("N ");
    if(j5)
        printf("%d", A5);
    else
        printf("N");
    return 0;
    
}