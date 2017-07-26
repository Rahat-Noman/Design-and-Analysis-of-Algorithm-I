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
int dis[mxn];
void dfs(int u , int level , int parent)
{
    dis[u] = level;
    for(int i = 0; i < (int) adj[u].size(); i++)
    {
        int v= adj[u][i];
        if(v != parent)
        dfs(v , level+1 , u);
    }
    return;
}
int main()
{
    int n , m;
    cin>>n;
    int u , v;
    for(int i  = 1; i < n ; i++)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0 , 0 , -1);
    int mx = -1 , id ;
    for(int i = 0; i < n ; i++)
    {
      mx = max( mx , dis[i]);
      if(mx==dis[i])
      id = i;
    }
    dfs( id , 0 , -1);
    mx = -1;
    for(int i = 0; i < n ; i++)
    {
      mx = max( mx , dis[i]);
    }
    cout<<mx<<endl;
    return 0;
}

