#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector< int > adj[100005];
const int mxn = 200002;
#define g 1
#define w 0
#define b 2
int vis[mxn];
bool flag =false;
void dfs(int u)
{
    vis[u] = g;
    for(int i = 0; i < (int) adj[u].size(); i++)
    {
        int v= adj[u][i];
        if(vis[v]==w)
        {
            dfs(v);
        }
        else if(vis[v]==g)
        {
        flag = true;
        }
    }
    vis[u] = b;
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
    }
    for(int i = 0; i < mxn ; i++)
        vis[i] = w;
    for(int i = 0; i < n ; i++)
    {
        if(vis[i]==w)
        {
            dfs(i);
        }
    }
    if(flag)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
    return 0;
}

