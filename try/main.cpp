#include <iostream>
#include <string>
using namespace std;
/*string concatenate (string& a, string& b)
{
    return a+b;
}
void duplicate(const int& a, int b, int c)
{
    a++;
    cout << "a: " << a << " b: " << b << " c: " << c << endl;
}
int main()
{
    string a, b;
    int x=1, y=2, z=3;
    cout << "x: " << x << " y: " << y << " z: " << z << endl;
    duplicate(x, y, z);
    cout << "x: " << x << " y: " << y << " z: " << z << endl;
    return 0;
}*/
template <class T>
T sum (T a, T b)
{
    T result;
    result = a + b;
    return result;
}
int main()
{
    int k = sum<int>(1,2);
    double j = sum<double>(2.4, 3.5);
    cout << k << endl;
    cout << j << endl;
    return 0;
}
