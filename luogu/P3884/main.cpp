#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int tree[100][3] = {0};
int Findroot(int n);
int Height(int root);
int Width(queue<int>& onelist);
int Path(int length, int u, int v, vector<int>& visited);
int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(tree[a][0] != 0)
            tree[a][1] = b;
        else
            tree[a][0] = b;
        tree[b][2] = a;
    }
    int u, v;
    scanf("%d %d", &u, &v);
    int root = Findroot(n);
    int height = Height(root);
    queue<int> onelist;
    onelist.push(root);
    int width = Width(onelist);
    vector<int> visited(n+1, 0);
    visited[u] = 1;
    int path = Path(0, u, v, visited);
    printf("%d\n%d\n%d", height, width, path);
    return 0;
}
int Findroot(int n)
{
    for(int i = 1; i <= n; i++)
        if(tree[i][2] == 0)
            return i;
    printf("there is no root!\n");
    return -1;
}
int Height(int root)
{
    //printf("Height...\n");
    if(tree[root][0] == 0 && tree[root][1] == 0)
        return 1;
    int leftheight = Height(tree[root][0]);
    int rightheight = Height(tree[root][1]);
    return max(leftheight, rightheight) + 1;
}
int Width(queue<int>& onelist)
{
    //printf("width...\n");
    if(onelist.empty())
        return 0;
    int tmpsize = onelist.size();
    for(int i = 0; i < tmpsize; i++)
    {
        if(tree[onelist.front()][0])
            onelist.push(tree[onelist.front()][0]);
        if(tree[onelist.front()][1])
            onelist.push(tree[onelist.front()][1]);
        onelist.pop();
    }
    return max(tmpsize, Width(onelist));
}
int Path(int length, int u, int v, vector<int>& visited)
{
    //printf("Path...\n");
    if(u == v)
        return length;
    int result = 0;
    bool flag = false;
    if(tree[u][0] && visited[tree[u][0]]==0)
    {
        flag = true;
        visited[tree[u][0]] = 1;
        result += Path(length + 1, tree[u][0], v, visited);
    }

    if(tree[u][1] && visited[tree[u][1]]==0)
    {
        flag = true;
        visited[tree[u][1]] = 1;
        result += Path(length + 1, tree[u][1], v, visited);
    }

    if(tree[u][2] && visited[tree[u][2]]== 0)
    {
        flag = true;
        visited[tree[u][2]] = 1;
        result += Path(length + 2, tree[u][2], v, visited);
    }

    if(flag==false)
        return 0;
    else
        return result;

}
