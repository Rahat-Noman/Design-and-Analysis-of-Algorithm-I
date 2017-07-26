#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector< int > adj[100005];
const int mxn = 20002;
int com[20002] ;
int dv[20002] , fin[20002];
bool vis[mxn];
int cnt = 1 , comp = 0;
void dfs(int u)
{
    vis[u] = true;
    com[u] = comp;
    dv[u] = cnt++;
    for(int i = 0; i < (int) adj[u].size(); i++)
    {
        int v= adj[u][i];
        if(!vis[v])
        {
            dfs(v);
        }
    }
    fin[u] = cnt++;
    return;
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
    for(int i = 0; i < n ; i++)
    {
        sort(adj[i].begin() , adj[i].end());
    }
    for(int i = 0; i < mxn ; i++)
        vis[i] = false;
    for(int i = 0; i < n ; i++)
    {
        if(!vis[i])
        {
            comp++;
            dfs(i);
        }
    }
    for(int i = 0; i < n ; i++)
    {
        cout<<i<<": "<<com[i]<<" "<<dv[i]<<" "<<fin[i]<<endl;
    }
    return 0;
}

