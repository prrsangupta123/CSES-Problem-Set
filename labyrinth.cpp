#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long int
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
#define mp make_pair
using namespace std;
void bfs(pair<int,int> pos,pair<int,int> end,vector<vector<int>>&a,int n,int m)
{
    vector<vector<int>>vis(n,vector<int>(m,0));
     vector<int> v1 ={-1,0,1,0};
      vector<int> v2 ={0,1,0,-1};
      string ss="URDL";
    queue<pair<int,int>>q;
    q.push(pos);
    vis[pos.first][pos.second]=1;
    int path[n][m];
    while(!q.empty())
    {
        pair<int,int> val=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int s=val.first+v1[i];
            int s1=val.second+v2[i];
            if(s<0 || s>=n || s1<0 || s1>=m)
            continue;
            else if(vis[s][s1]==1 || a[s][s1]==1)
            continue;
            else if(vis[s][s1]==0 && a[s][s1]==0)
            {
                vis[s][s1]=1;
                q.push(mp(s,s1));
                path[s][s1]=i;
            }
        }
    }
    vector<int>vec;
    if(vis[end.first][end.second]==1)
    {
        cout<<"YES"<<endl;
        while(end!=pos)
        {
            vec.push_back(path[end.first][end.second]);
            end=mp(end.first-v1[path[end.first][end.second]],end.second-v2[path[end.first][end.second]]);
        }
        cout<<vec.size()<<endl;
        for(int i=vec.size()-1;i>=0;i--)
        cout<<ss[vec[i]];
        cout<<endl;
    }
    else
    cout<<"NO"<<endl;

}
int main()
{
    ll n,m;
    cin>>n>>m;
    char x;
    pair<int,int> pos,end;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>x;
            if(x=='.')
            a[i][j]=0;
            else if(x=='#')
            a[i][j]=1;
            else if(x=='A')
            pos=mp(i,j);
            else if(x=='B')
            end=mp(i,j);
        }
    }
    bfs(pos,end,a,n,m);
}