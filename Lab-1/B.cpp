#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int mxn = 99999999;
vector< int > adj[100005];
int dis[100005];
void bfs(int u)
{
    for(int i= 0; i < 100005 ; i++)
    {
        dis[i] = mxn;
    }
    dis[u] = 0;
    queue< int > Q;
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
                Q.push(v);
            }
        }
    }


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
    }
    bfs(0);
    for(int i = 0; i < n ; i++)
    {
        if(dis[i]!= mxn)
        cout<<i<<": "<<dis[i]<<endl;
        else
        cout<<i<<": "<<"Not Reachable"<<endl;
    }
    return 0;
}
