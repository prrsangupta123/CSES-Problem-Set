#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long int
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
void dfs(int i,int j,vector<vector<int>>&a,ll n,ll m)
{
    vector<pair<int,int>> v ={{-1,0},{1,0},{0,-1},{0,1}};
    a[i][j]=1;
    for(auto k:v)
    {
        int s=i+k.first;
        int s1=j+k.second;
        if(s<0 || s>=n || s1<0 || s1>=m)
        continue;
        if(a[s][s1]==0)
        {
            a[s][s1]=1;
            dfs(s,s1,a,n,m);
        }
    }
    
}
int main()
{
    ll n,m;
    cin>>n>>m;
    char x;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
          //  cout<<"hi";
        cin>>x;
        //cout<<"hi";
        if(x=='#')
        a[i][j]=1;
        }
    }
    ll cnt=0;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]==0)
            {
                dfs(i,j,a,n,m);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
}