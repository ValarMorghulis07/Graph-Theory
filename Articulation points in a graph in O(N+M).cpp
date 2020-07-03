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
set<ll>ss;

void dfs(ll u,ll par)
{
 vis[u]=1;
 in[u]=low[u]=timer;
 timer++;
 ll child=0;
 for(auto x:adj[u])
 {
  if(x==par)
    continue;
  if(vis[x])
    low[u]=min(low[u],in[x]);
  else
  {
   dfs(x,u);
   if(low[x]>=in[u] && par!=-1)
    ss.insert(u);
   low[u]=min(low[u],low[x]);
   child++;
  }
 }
 if(par==-1 && child>1)// for root if this vertex has more than one child in the DFS tree
    ss.insert(u);
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
 ss.clear();
 rep(i,0,n)
 {
  if(!vis[i])
    dfs(i,-1);
 }
 if(ss.size()==0)
    cout<<"-1";
 for(auto x:ss)
    cout<<x<<" ";
 return 0;
}
