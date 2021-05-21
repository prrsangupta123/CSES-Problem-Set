#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define int long long
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
const int nax = 10e5 + 10;
void dfs(int i, vector<int> a[], vector<int> &vis,vector<int> &color,int n)
{
    //cout << u << " ";
    for (auto &k : a[i])
    {
        if (vis[k] == 0)
        {
            if(color[i]==1)
            {
                color[k]=2;
            vis[k]=1;
            }
            else
            {
                color[k]=1;
            vis[k]=1;
            }
            dfs(k, a, vis,color,n);
        }
        else
        {
            if (color[i] == color[k])
            {
                 cout<<"IMPOSSIBLE";
                exit(0);
            }
        }
    }
}
signed main()
{
    int n, m;
    cin >> n >> m;
    int a1, b;
    vector<int> a[n];
    for (int j = 0; j < m; j++)
    {
        //cout<<"hi";
        cin >> a1 >> b;
        a[a1 - 1].push_back(b - 1);
        a[b - 1].push_back(a1 - 1);
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    vector<int> vis(n, 0);
     vector<int> color(n, 0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            color[i]=1;
             dfs(i, a, vis, color,n);
        }
    } 
     for(int i=0;i<n;i++)
        cout<<color[i]<<" ";
        cout<<endl;       
}