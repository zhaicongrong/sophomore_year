#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
vector<pair<int,int> > adj[10001];
vector<bool> visited(10001, false);
priority_queue<pair<int ,int>, vector<pair<int, int> >, greater<pair<int, int> > > myQueue;
vector<int> dis(10001, INT_MAX);
int main()
{
    int n, m, s;
    scanf("%d %d %d", &n, &m, &s);
    for(int i = 0; i < m ;i++)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(a != b)
            adj[a].push_back(pair<int, int>(c, b));
    }
    for(int i = 0; i < adj[s].size(); i++)
    {
        if(adj[s][i].first < dis[adj[s][i].second])
        {
            dis[adj[s][i].second] = adj[s][i].first;
        }

    }
    dis[s] = 0;
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); i++)
    {
        myQueue.push(adj[s][i]);
    }
    while(!myQueue.empty())
    {
        while(!myQueue.empty() && visited[myQueue.top().second] == true)
            myQueue.pop();
        if(myQueue.empty())
            break;
        int node = myQueue.top().second;
        visited[node] = true;
        dis[node] = myQueue.top().first;
        for(int i = 0; i < adj[node].size(); i++)
        {
            dis[adj[node][i].second] = min(dis[adj[node][i].second], dis[node] + adj[node][i].first);
            myQueue.push(pair<int, int>(dis[adj[node][i].second], adj[node][i].second));
        }
        myQueue.pop();

    }
    for(int i = 1; i <= n; i++)
        if(i != n)
            printf("%d ", dis[i]);
        else
            printf("%d", dis[i]);
    return 0;
}
