#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int mxn = 99999999;
vector< int > adj[100005];
int dis[100005] , parent[100005];
void bfs(int u)
{
    for(int i= 0; i < 100005 ; i++)
    {
        dis[i] = mxn;
    }
    dis[u] = 0;
    queue< int > Q;
    parent[0] = -1;
    Q.push(u);
    while(!Q.empty())
    {
        u = Q.front();
        Q.pop();
        for(int i = 0; i < (int) adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dis[v] > dis[u]+1)
            {
                dis[v] = dis[u] + 1;
                parent[v] = u;
                Q.push(v);
            }
            else if(dis[v] == dis[u] + 1 && parent[v] > u)
            {
                parent[v] = u;
            }
        }
    }


}
void path(int u)
{
    if(u==-1)
    return;
    path(parent[u]);
    cout<<" "<<u;
}
int main()
{
    int n , m;
    cin>>n>>m;
    int u , v;
    for(int i  =0; i < m ; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);
    for(int i = 0; i < n ; i++)
    {
        cout<<i<<":";
        if(dis[i]!= mxn)
        path(i);
        else
        cout<<" Not Reachable";
        cout<<endl;
    }
    return 0;
}


