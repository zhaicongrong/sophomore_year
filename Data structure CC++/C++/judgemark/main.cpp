#include <iostream>
using namespace std;
#include <string>
#include <deque>
#include <vector>
#include <algorithm>
class Person
{
public:
    Person(string name, int score)
    {
        this->m_Name = name;
        this->score = score;
    }
    string m_Name;
    int score;
};
void CreatePerson( vector<Person>&v)
{
    string standard = "ABCDEF";
    for(int i = 0; i < 5; i++)
    {
        string name = "player";
        name += standard[i];
        Person p(name, 9);
        v.push_back(p);
    }
    cout << "finish Create!" << endl;
}
void SetPoint(vector<Person>&v)
{
    for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        deque<int> dq;
        for(int i = 0; i < 10; i++)
        {
            int tmpscore;
            cin >> tmpscore;
            dq.push_back(tmpscore);
        }
        sort(dq.begin(), dq.end());
        dq.pop_back();
        dq.pop_front();
        int sum = 0;
        for(deque<int>::iterator dit = dq.begin(); dit != dq.end(); dit++)
        {
            sum += (*dit);
        }
        double avg = sum / dq.size();
        (*it).score = avg;

    }
}
int main() {
    vector<Person> v;
    CreatePerson(v);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
