#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector< int > adj[100005];
const int mxn = 200002;
#define g 1
#define w -1
#define b 0
int vis[mxn];
bool flag =false;
void dfs(int u)
{
    for(int i = 0; i < (int) adj[u].size(); i++)
    {
        int v= adj[u][i];
        if(vis[v]== -1)
        {
            vis[v] = 1 - vis[u];
            dfs(v);
        }
        else if(vis[v]== vis[u])
        {
         flag = true;
        }
    }
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
    for(int i = 0; i < mxn ; i++)
        vis[i] = w;
    for(int i = 0; i < n ; i++)
    {
        if(vis[i]==w)
        {
            vis[i] = 0;
            dfs(i);
        }
    }
    if(flag)
    cout<<"No"<<endl;
    else
    cout<<"Yes"<<endl;
    return 0;
}

