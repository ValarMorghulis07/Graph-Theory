#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=1e5+7;
vector<ll>adj[N];
ll in[N],low[N];
bool vis[N];
ll n,e,timer;

void dfs(ll u,ll par)
{
 vis[u]=1;
 in[u]=low[u]=timer;
 timer++;
 for(auto x:adj[u])
 {
  if(x==par)
    continue;
  if(vis[x])// back edge is present ,which don't contribute in Bridges
   low[u]=min(low[u],in[x]);
  else // forward edge which may contribute in Bridges
  {
   dfs(x,u);
   if(low[x]>in[u])
    cout<<u<<"->"<<x<<"\n";
   low[u]=min(low[u],low[x]);
  }

 }
}

int main()
{
 hs;
 cin>>n>>e;
 rep(i,0,e)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
 }
 mem(vis,0);
 rep(i,0,n)
 {
  if(!vis[i])
    dfs(i,-1);
 }

 return 0;

}
