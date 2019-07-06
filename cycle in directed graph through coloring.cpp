#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define INF 1000000007
#define pb(x) push_back(x)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;

const ll N=2*100001;
vector<ll>adj[N];
ll color[N];
ll n,e,k;


ll dfs(ll u,ll parent)
{
    color[u]=1;
    for(ll i=0;i<adj[u].size();i++)
    {
        ll v=adj[u][i];
        if(color[v]==1)
            return 1;
        if(color[v]==0)
        {
            if(dfs(v,u))
                return 1;
        }

    }
    color[u]=2;
    return 0;
}
int main()
{
    hs;
    ll t;
    cin>>t;
    f(t)
    {
    cin>>n>>e;
    f(e)
    {
        ll x,y;
        cin>>x>>y;
        adj[x].pb(y);
    }
    mem(color,0);
    ll ff=0;
    for(ll i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(dfs(i,-1))
            {
              cout<<"Cycle found"<<endl;
              ff=1;
              break;

            }
        }
    }
    if(ff==0)
    {
        cout<<"cycle not found"<<endl;
    }
    f(N)
    {
        adj[i].clear();
    }
    }
    return 0;
}
