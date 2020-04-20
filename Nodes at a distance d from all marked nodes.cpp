#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi 3.141592653589793238462
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll INF=1e9+7;

const ll N=1e5+7;
vector<ll>adj[N];
ll dist[N],n,m,d,a[N],node,node1,dd=-1;
bool mark[N];

void dfs(ll u,ll par,ll lev)
{
 if(mark[u] && lev>=dd)
 {
  dd=lev;
  node=u;
 }
 for(auto x:adj[u])
 {
  if(x!=par)
   dfs(x,u,lev+1);
 }
}

void dfs2(ll u,ll par,ll lev)
{
 if(lev<=d)
    dist[u]++;
 for(auto x:adj[u])
 {
  if(x!=par)
    dfs2(x,u,lev+1);
 }
}

int main()
{
 hs;
 cin>>n>>m>>d;
 f(m)
 {
  cin>>a[i];
  mark[a[i]]=1;
 }

 f(n-1)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
 }
 dfs(1,0,0);
 node1=node;
 dfs(node,node,0);
 dfs2(node,node,0);
 dfs2(node1,node1,0);
 ll ans=0;
 for(ll i=1;i<=n;i++)
 {
  if(dist[i]==2)
    ans++;
 }
 cout<<ans<<"\n";
 return 0;
}
