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

const ll N=1e4+7;
vector<ll>adj[N];
ll node,n,dist;

void dfs(ll u,ll par,ll lev)
{
 if(lev>=dist)
 {
  dist=lev;
  node=u;
 }
 for(auto x:adj[u])
 {
  if(x!=par)
    dfs(x,u,lev+1);
 }
}


int main()
{
 hs;
 cin>>n;
 f(n-1)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
 }
 dist=-1;
 dfs(1,-1,0);
 dist=-1;
 dfs(node,-1,0);
 cout<<dist<<"\n";
 return 0;

}
