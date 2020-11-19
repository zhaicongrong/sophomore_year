#include <stdio.h>
#include <string.h>
#define MAXSIZE 30
int N;
int postL = 0;
int stackL = 0;
int find(int *a, int element)
{
    int i;
    for(i = 0; i < N; i++)
    {
        if(a[i] == element) return i;
    }
    return -1;
}
void split(int *preOrder, int preL, int *inOrder, int inL, int *postOrder, int n)
{
    if(n == 0)
        return;
    if(n == 1)
    {
        printf("new element: %d, postL:%d\n",preOrder[preL], postL);
        postOrder[postL--] = preOrder[preL];
        return;
    }
    int i = find(inOrder, preOrder[preL]);
    int L = i - inL;
    int R = n - L - 1;
    postOrder[postL--] = preOrder[preL];
    printf("i:%d preL:%d inL:%d L:%d R:%d\n",i, preL, inL, L, R);
    split(preOrder, preL + 1 + L, inOrder, i + 1, postOrder, R);
    split(preOrder, preL + 1, inOrder, inL, postOrder, L);
    return;
}

int main()
{
    scanf("%d", &N);
    postL = N - 1;
    int stack[MAXSIZE] = {0};
    int preOrder[MAXSIZE]={0}, inOrder[MAXSIZE]={0}, postOrder[MAXSIZE]={0};
    int pre = 0, in = 0, post = 0;
    for(int i = 0; i < 2 * N; i++)
    {
        char s[5];
        int index;
        scanf("%s", s);
        if(strcmp(s, "Push") == 0)
        {

            scanf("%d", &index);
            preOrder[pre++] = index;
            stack[stackL++] = index;
        }
        else
        {
            inOrder[in++] = stack[--stackL];
        }
    }
    split(preOrder, 0, inOrder, 0, postOrder, N);
    printf("!!=%d",postOrder[0]);
    for(int j = 0; j < N; j++)
        if(j == 0)
            printf("%d",postOrder[j]);
        else
            printf(" %d",postOrder[j]);
    //getchar();getchar();
    return 0;
}
