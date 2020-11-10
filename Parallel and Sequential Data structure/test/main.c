#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[100];
    gets(a);
    int l,i;
    l = strlen(a);
    for(i=0;i<l;i++)
    {
        char A,B,C,D,E,F,G,n;
        A=(a[i]&1)<<1;
        B=(a[i]&2)>>1;
        C=(a[i]&4)<<1;
        D=(a[i]&8)>>1;
        E=(a[i]&16)<<1;
        F=(a[i]&32)>>1;
        G=a[i]&0x3f;
        n=A|B|C|D|E|F|G;
        a[i]=n;
    }
    for(i=0;i<l;i++)
    {
        char n,m;
        short int k;
        k=a[0]>>6;
        a[i]=a[i]&0x3f;
        n=(a[i]<<2)&(0xff<<(8-k));
        m=n>>(8-k);
        a[i]=a[i]<<(k+2);
        a[i]=a[i]>>2;
        a[i]=a[i]|m;
    }
    printf("%s",a);
    return 0;
}
