#include <iostream>
#include <cstdio>
using namespace std;
int n, k;
int a[10001];
void myswap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
    return;
}
void insert_sort(int a[], int left, int right)
{
    for(int i = left + 1; i <= right; i++)
    {
        int tmp = a[i];
        int j = i - 1;
        for(; j >= left; j--)
        {
            if(a[j] >= tmp)
            {
                a[j+1] = a[j];
            }
            else
            {
                break;
            }
        }
        if(j < left)
            a[left] = tmp;
        else
            a[j+1] = tmp;

    }
}
void quicksort(int a[], int left, int right)
{
    //printf("!");
    if(right - left + 1 >= 100)
    {
    if(left >= right)
        return;
    int pivot  = a[left];
    int i = left + 1;
    int j = right;
    while(true)
    {
        while(i <= right && a[i] <= pivot) i++;
        while(j >= left + 1 && a[j] >= pivot) j--;
        if(i < j)
            myswap(&a[i], &a[j]);
        else
            break;
    }
    myswap(&a[left], &a[i - 1]);
    //for(int i = 0; i < n; i++)
      //  printf("%d ", a[i]);
    //cout << endl;
    quicksort(a, left, i - 2);
    quicksort(a, i, right);
    return;
    }
    else
        insert_sort(a, left, right);

}
int main()
{
    scanf("%d %d", &n, &k);
    if(k > n)
    {
        printf("NO RESULT");
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        //printf("i:%d", i);
        scanf("%d", &a[i]);
        //printf("\n");
    }
    quicksort(a, 0, n - 1);
    //for(int i = 0 ; i < n; i++)
    //    printf("%d ", a[i]);
    //cout << endl;
    int i = 0;
    for(; i < k && k <= n; i++)
    {
        if(i > 0 && a[i] == a[i - 1])
            k++;
    }
    if(k > n)
        printf("NO RESULT");
    else
        printf("%d", a[i - 1]);
    return 0;
}
