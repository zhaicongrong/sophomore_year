#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
string in, last, pre;
int Find(char c)
{
    for(unsigned int i = 0; i < in.size(); i++)
        if(in[i] == c)
            return i;
    return -1;
}
void exec(int lastleft, int lastright, int inleft, int inright)
{
    if(lastleft > lastright)
        return;
    if(lastleft == lastright)
    {
        printf("%c", last[lastleft]);
        return;
    }
    int root = lastright;
    int rootlocation = Find(last[root]);
    printf("%c", last[root]);
    int leftlength = rootlocation - inleft;
    int rightlength = inright - rootlocation;
    exec(lastleft, leftlength + lastleft - 1, inleft, rootlocation - 1);
    exec(lastright - rightlength, lastright - 1, rootlocation+1, inright);
    return;
}
int main()
{
    cin >> in;
    cin >> last;
    exec(0, last.size() - 1, 0, in.size() - 1);

    return 0;
}
