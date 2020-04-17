#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi 3.1415926535897932384626433832795
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll INF=1e9+7;

const ll N=2*(1e5)+7;
vector<ll>adj[N];
ll depth[N],subtree[N];
ll n,k;

void dfs(ll u,ll par)
{
 depth[u]=depth[par]+1;
 subtree[u]=1;
 for(auto x:adj[u])
 {
  if(x!=par)
  {
   dfs(x,u);
   subtree[u]+=subtree[x];
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
 for(ll i=1;i<=n;i++)
    cout<<depth[i]<<" "<<subtree[i]<<"\n";
 return 0;

}

/*
https://codeforces.com/contest/1337/problem/C
*/
