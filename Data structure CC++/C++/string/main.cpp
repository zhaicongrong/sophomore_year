#include <iostream>
#include <string>
using namespace std;
void test01()
{
//    string str1;
//    str1 = "hello world";;
//    cout << "str1= " << str1 << endl;
//
//    string str2;
//    str2 = str1;//"hello world"
//
//    string str3;
//    str3 = 'a';
//
//    string str4;
//    str4.assign("hello c++");//利用assign赋值
//
//    string str5;
//    str5.assign("hello c++", 5);//取前5个字符
//    cout << str5 << endl;
//
//    string str6;
//    str6.assign(str5);//拷贝构造
//
//    string str7;
//    str7.assign(10, 'w');//wwwwwww
    string str = "hello";
    cout << str.insert(1, "111") << endl;
    cout << str.erase(1, 3) << endl;


}
int main() {
    const char * str = "hello world";
    string s2(str);
    test01();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
