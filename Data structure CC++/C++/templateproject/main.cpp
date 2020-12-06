#include <iostream>
#include <string.h>
using namespace std;
template<class T>
void mySwap(T&a, T&b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
template<class T>
void mySort(T arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        int max = i;
        for(int j = i + 1; j < len; j++)
            if(arr[max] < arr[j])
                max = j;
        if(max != i)
            mySwap(arr[i], arr[max]);
    }
}
template<class T>
void printArray(T arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test01()
{
    char charArr[] = "badcfe";
    int len = strlen(charArr);
    mySort(charArr, len);
    printArray(charArr, len);
}
int main() {
    test01();
    system("pause");
    return 0;
}
