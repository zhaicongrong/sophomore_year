#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<pair<int, int> > myQueue;
    myQueue.push(pair<int, int>(2,3));
    cout << myQueue.front().first;
    return 0;
}
