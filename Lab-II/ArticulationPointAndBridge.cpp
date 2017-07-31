#include<bits/stdc++.h>

using namespace std;

int dfs_num[100], dfs_low[100], dfs_parent[100];

typedef pair< int , int > ii;
typedef vector< ii> vii;
typedef vector< int > vi;

vii bridge;
vi AP;

int dfsNumbercounter = 0;

void ArticulationPointAndBridge( int  u)
{
    dfs_num[u] = dfs_low[u] = dfsNumbercounter ++;
    for( int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if( dfs_num[v] == unvisited)
        {
            dfs_parent[v] = u;
            if( u == dfsroot)
                rootchildren++;
            ArticulationPoinAndBridge(v);
            if(dfs_low[v] >= dfs_num[u])
                Ap.push_back(u);
            if(dfs_low[v] > dfs_num[u])
            {
                ii p;
                p.first = u ;
                p.second = v;
                bridge.push_back(p);
            }
            dfs_low[u] = min ( dfs_low[u] , dfs_low[v]);
        }
        else if( v != dfs_parent[u])
        {
            dfs_low[u] = min( dfs_low[u] , dfs_num[v]);
        }

    }
}


int main()
{
    memset()
    for(int i = 0 ; i < AP.size() ; i++)
    {
        cout<<AP[i] << " ";
    }
    cout<<endl;
    for( int i = 0 ; i < bridge.size() ; i++)
    {
        cout<< bridge[i].first << "->"<<bridge[i].second<<endl;
    }
    return 0;
}
