#include <iostream>
#include <string>
using namespace std;
const double PI = 3.14;
class Circle
{
    //public root
public:
    //property
    int m_r;

    //action
    //get diameter
    double calculate()
    {
        return 2 * PI * m_r;
    }
};
class Student{
public:
    string m_Name;
    int m_Id;
    void showStudent()
    {
        cout << "name:" << m_Name << "code: " << m_Id << endl;
    }
};
class Person
{
public:
    string m_Name;

protected:
    string m_Car;

private:
    int m_Password;

private:
    void func()
    {
        m_Name = "hello";
        m_Car = "truck";
        m_Password = 123456;
    }
};
int main() {
    //通过圆类创建具体的圆（对象）
    Circle c1;
    c1.m_r = 10;
    cout << "圆的周长为："<< c1.calculate() << endl;
    Student s1;
    s1.m_Name = "zhangsan";
    s1.m_Id = 1;
    s1.showStudent();
    Person p1;
    p1.m_Name = "hey";
    p1.func();
    return 0;
}
