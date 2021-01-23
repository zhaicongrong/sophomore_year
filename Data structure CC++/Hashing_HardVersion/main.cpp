#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
vector<int> G[1000];
int myFind(int N, int myarray[], int element)
{
    for(int i = 0; i < N; i++)
        if(myarray[i] == element)
            return i;
    return 0;
}
void topSort(int N, vector<int>& Indegree, int myarray[])
{
    bool a[N];
    for(int i = 0; i < N; i++)
        if(myarray[i] < 0)
            a[i] = true;
        else
            a[i] = false;
    set<int> st;
    for(int i = 0; i < N; i++)
        if(Indegree[i] == 0)
        {
            st.insert(myarray[i]);
            a[i] = true;
        }
    while(!st.empty())
    {
        int ele = *st.begin();
        st.erase(ele);
        int point = myFind(N, myarray, ele);
        for(unsigned int i = 0; i < G[point].size(); i++)
        {
            int point2 = myFind(N, myarray, G[point][i]);
            Indegree[point2]--;
            if(Indegree[point2] == 0 && a[point2] == false)
            {
                st.insert(G[point][i]);
                a[point2] = true;
            }
        }
        if(st.empty())
            cout << ele;
        else
            cout << ele << " ";
    }
    return;
}
int main()
{
    int N;
    cin >> N;
    int myarray[N];
    vector<int> Indegree(N, 0);
    for(int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp < 0)
        {
            myarray[i] = -1;
            Indegree[i] = -1;
        }
        else
        {
            myarray[i] = tmp;
            Indegree[i] = i - (tmp % N);
            while(Indegree[i] < 0)
                Indegree[i] += N;
        }
    }
    for(int i = 0; i < N; i++)
    {
        if(Indegree[i] > 0)
        {
            int j = myarray[i] % N;
            while(j % N != i)
            {
                if(myarray[j % N] != -1)
                    G[j % N].push_back(myarray[i]);
                j++;
            }

        }
    }
    topSort(N, Indegree, myarray);
    return 0;
}
