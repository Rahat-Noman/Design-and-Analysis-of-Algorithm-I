#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair< int , int > PII;
const int mxn = 99999;
string str[105];
int dis[105][105];
int r , c;
int dr[] = {1 , 0 , -1 , 0};
int dc[] = {0 , 1 , 0 , -1};
void bfs(int x , int y)
{
//cout<<"called"<<endl;
    for(int i = 0; i < 105 ; i++)
    {
        for(int j = 0; j < 105 ; j++)
        {
            dis[i][j] = mxn;
        }
    }
    queue< PII > Q;
    Q.push(make_pair(x , y));
    dis[x][y] = 0;
    while(!Q.empty())
    {
        PII p = Q.front();
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            x = p.first + dr[i];
            y = p.second + dc[i];
            if(x >= 0 && x < r && y >= 0 && y < c && str[x][y] != '#' && dis[x][y] > dis[p.first][p.second] + 1)
            {
                dis[x][y] = dis[p.first][p.second] + 1;
                Q.push(make_pair(x , y));
            }
        }
    }
}

int main()
{
    cin>>r>>c;
    for(int i = 0; i < r ; i++)
        cin>>str[i];
       // cout<<"finished"<<endl;
    dis[r-1][c-1] = mxn;
    if(str[0][0]!= '#')
    bfs(0 , 0);
    if(dis[r-1][c-1]==mxn)
    {
        cout<<"-1"<<endl;
    }
    else
    cout<<dis[r-1][c-1]<<endl;
}
