#include <math.h>
#include <bits/stdc++.h>
#include <deque>
#define ll long long int
#define l long double
#define pi 3.14159265358979323846
#define mod 1000000007
#define vali 1000000000000000000
using namespace std;
const int nax = 10e5+10;
vector<int > vis(nax, 0);
queue<int>q;
void bfs(int i,vector<int>a[],int n)
{
    vis[i] = 1;

   // q.push(i);
    int path[n+1];
    while(!q.empty())
    {
        int aa=q.front();
       // cout<<"hhh   "<<aa<<endl;
        q.pop();
        for(auto &k:a[aa])
        {
            if(vis[k]==0)
            {
                //cout<<k<<endl;
                vis[k]=1;
                q.push(k);
                path[k]=aa;
                
            }
        }

    }
    // for(int ii=1;ii<=n;ii++)
    // cout<<path[ii]<<" ";
    // cout<<endl;
    vector<int>nodes;
    if(vis[n]==1)
    {
        nodes.push_back(n);
        while((n)!=1)
        {
        int s=path[n];
        nodes.push_back(s);
        n=s;
        }
        cout<<nodes.size()<<endl;
        for(int i=nodes.size()-1;i>=0;i--)
        cout<<nodes[i]<<" ";
        cout<<endl;
    }
    else
    {
    cout<<"IMPOSSIBLE"<<endl;
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
    vector<int>a[n+1];
        for(int j=1;j<=m;j++)
        {
           //cout<<"hi";
        cin>>a1>>b;
        a[a1].push_back(b);
        a[b].push_back(a1);
        }
        q.push(1);
    bfs(1,a,n);
}