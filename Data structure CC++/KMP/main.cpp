#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
using namespace std;
void getLength(int len, int next[], string& b);
int KMP(string& a, string& b, int next[]);
int main()
{
    string a, b;
    cin >> a >> b;
    int length = b.size();
    int next[length];
    getLength(length, next, b);
    for(int i = 0; i < length; i++)
        cout << next[i] << " ";
    cout << "\n";
    cout << KMP(a, b, next);
    return 0;
}
int KMP(string& a, string& b, int next[])
{
    int i = 0;
    int j = 0;
    int len1 = a.size();
    int len2 = b.size();
    while(i < len1 && j < len2)
    {
        if(j == -1 || a[i] == b[j])
        {
            i++;j++;
        }
        else
            j = next[j];
    }
    printf("i=%d j=%d\n", i, j);
    if(j == len2)
        return i - j;
    else
        return -1;

}
void getLength(int len, int next[], string& b)
{
    next[0] = -1;
    int i = 0;
    int j = -1;
    while(i < len - 1)
    {
        if(j == -1 || b[i] == b[j])
        {
            ++i;++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
