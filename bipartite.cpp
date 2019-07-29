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
ll n,e,ff=0;
bool vis[N];
bool color[N];

bool isbipartite(ll u,bool col)
{
 vis[u]=1;
 color[u]=col;
 f(adj[u].size())
 {
  ll v=adj[u][i];
  if(!vis[v])
  {
    isbipartite(v,1-col);
  }
  else if(col==color[v])
     ff=1;
 }
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  f(N)
   adj[i].clear();
   cin>>n>>e;
  f(e)
  {
    ll x,y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  mem(vis,0);
  mem(color,0);
  ff=0;
  for(ll i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      isbipartite(i,0);
      if(ff==1)
      {
        cout<<"Not bipartite"<<endl;
         break;
      }
    }
  }
  if(ff==0)
    cout<<"bipartite"<<endl;

 }
 return 0;
}
