#include <bits/stdc++.h>
#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;
class Person
{
public:
    Person(string name, int age, int height)
    {
        this->Name = name;
        this->Age = age;
        this->Height = height;
    }
    string Name;
    int Age;
    int Height;
};
void CreatePerson(list<Person>&v)
{
    Person p1("刘备", 35 , 175);
    Person p2("曹操", 45 , 180);
    Person p3("孙权", 40 , 170);
    Person p4("赵云", 25 , 190);
    Person p5("张飞", 35 , 160);
    Person p6("关羽", 35 , 200);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    v.push_back(p6);
}
bool myCompare(Person& p1, Person& p2)
{
    if(p1.Age ==  p2.Age)
        return p1.Height < p2.Height;
    else
        return p1.Age < p2.Age;
}
using namespace std;
int main() {
    list<Person> v;
    CreatePerson(v);
    v.sort(myCompare);
    list<Person>::iterator it = v.begin();
//    while(!v.empty()){
//        cout << "name: " << (*it).Name << " Age:" << (*it).Age << " height:" << (*it).Height << endl;
//        v.pop_front();
//        it = v.begin();
//    }
    for(list<Person>::iterator iit = v.begin(); iit != v.end(); iit++)
        cout << "name: " << (*iit).Name << " Age:" << (*iit).Age << " height:" << (*iit).Height << endl;

    return 0;
}
