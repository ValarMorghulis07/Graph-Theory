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
int FCB=1e9+7;
ll prime=119;
ll dir[][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=2e5+7;
vector<ll>adj[N];
ll lev[N],pp[N][21];
ll n;

void dfs(ll u,ll par)
{
 lev[u]=1+lev[par];
 pp[u][0]=par; // just storing immediate parent of each node (i.e--> at distance (2^0==1)
 for(auto xx:adj[u])
 {
  if(xx!=par)
     dfs(xx,u);
 }
}

ll lca(ll u,ll v) // finding lca
{
 if(lev[u]<lev[v])
    swap(u,v); // just keeping u at more level
 ll up=0;
 while((1LL<<up)<=lev[u]) // just finding the binary power which lower or equal to lev[u] (i.e--> if(lev[u]=3 then finding 2(here up=1-->2^up))
    up++;
 up--;

 for(ll i=up;i>=0;i--) // from this we want to bring u at such node whose level is same as v
 {
  if(lev[u]-(1LL<<i)>=lev[v])
    u=pp[u][i];
 }

 if(u==v)
    return u;

 for(ll i=up;i>=0;i--)
 {
  if(pp[u][i]!=-1 && pp[u][i]!=pp[v][i]) // from this complete loop we finally want to reach at nodes which are just the immediate lca of u and v
    u=pp[u][i],v=pp[v][i];
 }

 return pp[u][0]; // finally returning its parent (which is lca)

}

ll dist(ll u,ll v) // returning distance b/w two nodes
{
 if(lev[u]<lev[v])
    swap(u,v);
 ll w=lca(u,v);
 return lev[u]+lev[v]-2*lev[w];
}

ll getAncestor(ll u,ll k) // finding ancestor at distance k from u
{
 k=lev[u]-k;
 ll up=0;
 while((1LL<<up)<=lev[u])
    up++;
 up--;
 for(ll i=up;i>=0;i--)
 {
  if(lev[u]-(1LL<<i)>=k) // binary lifting
    u=pp[u][i];
 }
 return u;
}

int main()
{
 hs;
 cin>>n;
 rep(i,0,n-1)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
 }
 ll a,b,k;
 cin>>a>>b>>k;
 rep(i,0,21)
  rep(j,0,n+1)
    pp[j][i]=-1; // parent of j at distance 2^i from it;
 lev[0]=-1;
 dfs(1,0);

 rep(i,1,21)
 {
  rep(j,1,n+1)
  {
   if(pp[j][i-1]!=-1) // if not reaching unexisting node
     pp[j][i]=pp[pp[j][i-1]][i-1]; // Binary lifting
  }
 }
 cout<<lca(a,b)<<" "<<dist(a,b)<<" "<<getAncestor(a,k)<<"\n";
 return 0;
}

/*
8
1 2
1 3
2 6
3 4
3 5
6 7
6 8
8 4 2
*/
