#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

const ll N=2*100007;
vector<ll>adj[N];
bool vis[N];
ll n,k;
ll ways[N];

void dfs(ll u,ll level)
{
  vis[u]=1;
  if(level==0)
    ways[u]=k;
  ll j=(level==0) ? 1:2;
  for(ll i=0;i<adj[u].size();i++)
  {
    ll v=adj[u][i];
    if(!vis[v])
    {
     ways[v]=k-j;
     j++;
     dfs(v,1);
    }
  }
}

int main()
{
  hs;

    cin>>n>>k;
    f(n-1)
    {
     ll x,y;
     cin>>x>>y;
     adj[x].pb(y);
     adj[y].pb(x);
    }

    dfs(1,0);
    ll way=1;
    for(ll i=1;i<=n;i++)
    {
      way=(way*ways[i])%INF;
    }
    cout<<way<<endl;


  return 0;
}
