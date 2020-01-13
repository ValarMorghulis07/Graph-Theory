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
ll a[N][N];
ll n,e;

bool bfs(ll src,ll dest,ll parent[])
{
 bool vis[n];
 mem(vis,0);
 queue<ll>q;
 q.push(src);
 vis[src]=1;
 parent[src]=-1;
 while(!q.empty())
 {
  ll u=q.front();
  q.pop();
  for(ll v=0;v<n;v++)
  {
   if(!vis[v] && a[u][v]>0)
   {
    q.push(v);
    parent[v]=u;
    vis[v]=1;
   }
  }
 }
 return (vis[dest]==1);
}

void fordfulkerson(ll src,ll dest)
{
 ll parent[n];
 ll maxflow=0;
 while(bfs(src,dest,parent))
 {
  ll flow=HRX;
  for(ll v=dest;v!=src;v=parent[v])
  {
   ll u=parent[v];
   flow=min(flow,a[u][v]);
  }
  for(ll v=dest;v!=src;v=parent[v])
  {
   ll u=parent[v];
   a[u][v]-=flow;
   a[v][u]+=flow;

  }
  maxflow+=flow;
 }
 cout<<maxflow<<endl;


}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>n>>e;
  mem(a,0);
  f(e)
  {
    ll x,y,w;
    cin>>x>>y>>w;
    x--;
    y--;
    a[x][y]+=w;
    a[y][x]+=w;
  }
  fordfulkerson(0,n-1);
 }
 return 0;

}
