#include <bits/stdc++.h>
#include <string>
using namespace std;
Class Element
{
public:
    Element(string singleelement, int number)
    {
        this->Singleelement = singleelement;
        this->Number = number;
    }
    string Singleelement;
    int Number;
}
bool execute(void)
{
    string s;
    cin >> s;
    int num = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            num++;
    }
    if(num % 2 != 0)
        return false;
    Element p1[num / 2];
    Element p2[num / 2];
    int top = 0;
    int tmpnum = 0;
    int ptr = 0;
    while(s[ptr] != '=')
    {
        if(s[ptr] >= 'A' && s[ptr] <= 'Z')
        {
            if(s[ptr+1] >= 'A' && s[ptr+1] <= 'Z')
            {
                if(num == 0)
                    p1[top++](s[ptr], 1);
                else
                    p1[top++](s[ptr], tmpnum);
            }
            else
            {
                if(num == 0)
                    p1[top++](substr(ptr, 2), 1);
                else
                    p1[top++](substr(ptr, 2), tmpnum);
            }
            num = 0;
        }
        if(s[ptr] >= '0' && s[ptr] <= '9')
        {
            tmpnum = (tmpnum) * 10 + s[ptr] - '0';
        }
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        if(execute())
            printf("Y\n");
        else
            printf("N\n");
    }
    cout << "Hello world!" << endl;
    return 0;
}
