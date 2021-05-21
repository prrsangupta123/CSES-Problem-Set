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
void dfs(int i, int p,vector<int> a[], vector<int> &vis,vector<int> &parent,int n)
{
    cout<<"i "<<i<<endl;
     cout<<"p "<<p<<endl;
    int c=0;
    vis[i]=1;
    parent[i]=p;
    for(auto w:parent)
    cout<<w<<" ";
    cout<<endl;
    //cout << u << " ";
    for (auto k : a[i])
    {
        if (vis[k] == 0)
        {
            cout<<" unvis k "<<k<<endl;
            dfs(k,i, a, vis,parent,n);
        }
        else
        {
            if(p!=k)
            {
                cout<<"parent "<<p<<endl;
                cout<<"k is "<<k<<endl;
                vector<int>cyc;
                int ii=i;
                cyc.push_back(i);
                cout<<i<<endl;
                while(parent[ii]!=k)
                {
                    cout<<"hh "<<parent[ii]<<endl;
                    ii=parent[ii];
                    cyc.push_back(ii);
                }
                cyc.push_back(k);
                cyc.push_back(i);
                cout<<cyc.size()<<endl;
                for(auto s:cyc)
                cout<<s<<" ";
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
    vector<int> a[n+1];
    for (int j = 1; j <= m; j++)
    {
        //cout<<"hi";
        cin >> a1 >> b;
        a[a1].push_back(b);
        a[b].push_back(a1);
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    vector<int> vis(n+1, 0);
    vector<int>parent(n+1,-1);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
             dfs(i, -1,a, vis,parent,n);
        
    }   
    cout<<"IMPOSSIBLE"<<endl;  
}