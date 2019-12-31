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

const ll N=1e3+7;
vector<ll>adj[N];
bool vis[N];
ll a[N][N];
vector<ll>ans;
ll n;

void bfs(ll src)
{
 mem(vis,0);
 ll dist[n];
 f(n)
  dist[i]=HRX;
 dist[src]=0;
 queue<ll>q;
 if(!vis[src])
    vis[src]=1;
 q.push(src);
 while(!q.empty())
 {
  ll u=q.front();
  q.pop();
  f(adj[u].size())
  {
    ll v=adj[u][i];
    if(!vis[v])
    {
     vis[v]=1;
     dist[v]=dist[u]+1;
     q.push(v);
    }
  }
 }
 f(n)
 {
  if(dist[i]!=HRX)
    ans.pb(1);
  else
    ans.pb(0);
 }
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>n;
  f(n)
  {
    r(n)
    {
     cin>>a[i][j];
     if(a[i][j]==1)
        adj[i].pb(j);
    }
  }
  f(n)
   bfs(i);
  f(ans.size())
   cout<<ans[i]<<" ";
  cout<<"\n";
  f(N)
   adj[i].clear();
  ans.clear();

 }
 return 0;
}
