/** KMP algorithm template
 *
 * You should know how next[n] come
 * And also how to use next[n] to jump and translate string s2
 *
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;
char s1[1000001];
char s2[1000001];
int next[1000001] = {0};
void getNext(char* s2)
{
    next[0] = -1;
    int i = 0;
    int j = -1;
    int l2 = strlen(s2);
    while(i < l2)
    {
        if(j == -1 || s2[i]==s2[j])
        {
            i++;j++;
            next[i] = j;
        }
        else
            j = next[j];
        //printf("next...\n");
    }
}
void KMP(char* s1, char* s2)
{
    int i = 0;
    int j = 0;
        //printf("KMP...\n");
        int l1 = strlen(s1);
        int l2 = strlen(s2);
        while(i < l1 && j < l2)
        {
            if(j == -1 || s1[i] == s2[j])
            {
                i++;j++;
            }
            else
            {
                j = next[j];
            }

        if(j == l2)
        {
            printf("%d\n", i - j + 1);
            j = next[j];
        }
    }
}
int main()
{
    cin >> s1;
    cin >> s2;

    getNext(s2);

    KMP(s1, s2);
    int l2 = strlen(s2);
    for(int i = 1; i <= l2; i++)
        printf("%d ", next[i]);
    return 0;
}
