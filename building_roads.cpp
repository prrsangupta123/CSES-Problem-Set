#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long int
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
const int nax = 1e5+5;
vector<int > vis(nax, 0);
void dfs(int i,vector<int>a[],vector<int>&vis)
{
    vis[i] = 1;
    //cout << u << " ";
    for(auto &k:a[i])
    {
        if(vis[k]==0)
        {
            vis[k]=1;
            dfs(k,a,vis);
        }
    }
    // for (int ii=0; ii<a[i].size(); ii++)
    //     if (vis[a[i][ii]] == 0)
    //         dfs(a[i][ii], a,n, vis);
    
}
int main()
{
    ll n,m;
    cin>>n>>m;
    int a1,b;
    vector<int>a[n];
        for(int j=0;j<m;j++)
        {
           //cout<<"hi";
        cin>>a1>>b;
        a[a1-1].push_back(b-1);
        a[b-1].push_back(a1-1);
        }
    ll cnt=0;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    vector<int>q;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            {
                q.push_back(i+1);
                dfs(i,a,vis);
                cnt++;
            }
    }
    cout<<cnt-1<<endl;
    for(int i=0;i<(int)(q.size()-1);i++)
    {
    cout<<q[i]<<" "<<q[i+1]<<endl;
    }
}