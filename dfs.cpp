#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof dp)
#define INF 1000000007
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;

const ll N=10000;
vector<ll>adj[N];

void dfsutil(ll v,bool vis[])
{
    vis[v]=true;
    cout<<v<<" ";
    for(ll i=0;i<adj[v].size();i++)
    {
        ll s=adj[v][i];
        if(!vis[s])
        {
            dfsutil(s,vis);
        }
    }

    f(N)
    {
      adj[i].clear();
    }
    cout<<"\n";
}
void dfs(ll v)
{
    bool vis[N];
    f(N)
    {
        vis[i]=false;
    }
    dfsutil(v,vis);
}

int main()
{
    hs;
    ll t;
    cin>>t;
    f(t)
    {
        ll m;
        cin>>m;
        ll directed;
        cin>>directed;
        if(directed)
        {
          f(m)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);

        }
        }
        else
        {
        f(m)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        }
        ll start;
        cin>>start;
        dfs(start);


    }
    return 0;

}
/*
https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem
https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
*/
