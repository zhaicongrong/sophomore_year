#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
//void myprint(int i)
//{
//    cout << i << endl;
//}
//class Person
//{
//public:
//    Person(string name, int age)
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    }
//    string m_Name;
//    int m_Age;
//};
//void test01()
//{
//    /*vector<int> v;
//    v.push_back(10);
//    v.push_back(20);
//    v.push_back(30);
//    v.push_back(40);*/
//
//    //vector<int>::iterator itBegin = v.begin();
//    //vector<int>::iterator itEnd = v.end();
//   /* while(itBegin != itEnd)
//    {
//        cout << *itBegin << endl;
//        itBegin++;
//    }
//    for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << *it << endl;
//    }*/
//    vector<Person> v;
//    //for_each(v.begin(), v.end(), myprint);
//    Person p1("aaa", 10);
//    Person p2("eee", 20);
//    Person p3("bbb", 30);
//    Person p4("ddd", 40);
//    Person p5("ccc", 50);
//    v.push_back(p1);
//    v.push_back(p2);
//    v.push_back(p3);
//    v.push_back(p4);
//    v.push_back(p5);
//    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
//        cout << "Name:" << (*it).m_Name << " Age:" << (*it).m_Age << endl;
//}
//void test02(void)
//{
//    vector<Person*> v;
//    Person p1("aaa", 10);
//    Person p2("eee", 20);
//    Person p3("bbb", 30);
//    Person p4("ddd", 40);
//    Person p5("ccc", 50);
//    v.push_back(&p1);
//    v.push_back(&p2);
//    v.push_back(&p3);
//    v.push_back(&p4);
//    v.push_back(&p5);
//    for(vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
//        cout << "Name:" << (**it).m_Name << " Age:" << (**it).m_Age << endl;
//}
void test01() {
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    for (int i = 0; i < 4; i++) {
        v1.push_back(i + 1);
        v2.push_back(i + 2);
        v3.push_back(i + 3);
        v4.push_back(i + 4);
    }
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        for(vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++)
            cout << *vit << "";
        cout << endl;
    }
}
int main() {
    //test01();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
