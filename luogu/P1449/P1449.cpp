#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <math.h>
using namespace std;
int main()
{
    stack<int> myStack;
    string s;
    cin >> s;
    int a, b;
    int len = s.size();
    for(int i = 0; i < len; i++)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            int tmp = s[i] - '0';
            while(s[++i] != '.')
                tmp = tmp * 10 + s[i] - '0';
            myStack.push(tmp);
        }
        else
        {
            switch(s[i])
            {
                case '@' : break;
                case '+' : a = myStack.top();
                            myStack.pop();
                            b = myStack.top();
                            myStack.pop();myStack.push(a + b);
                            break;
                case '-' : a = myStack.top();
                            myStack.pop();
                            b = myStack.top();
                            myStack.pop();
                            myStack.push(b - a);
                            break;
                case '*' : a = myStack.top();
                            myStack.pop();
                            b = myStack.top();
                            myStack.pop();
                            myStack.push(a * b);
                            break;
                case '/' : a = myStack.top();
                            myStack.pop();
                            b = myStack.top();
                            myStack.pop();
                            myStack.push(b / a);
                            break;
                case '^' : a = myStack.top();
                            myStack.pop();
                            b = myStack.top();
                            myStack.pop();
                            myStack.push((int)pow(b, a));
                            break;
            }
        }
        

    }
    printf("%d", myStack.top());
    return 0;
}