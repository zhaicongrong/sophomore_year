#include <iostream>
#include <string>
using namespace std;
string concatenate (string& a, string& b)
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
}
