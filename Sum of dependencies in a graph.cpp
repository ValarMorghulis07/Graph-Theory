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

const ll N=1007;
vector<ll>adj[N];
ll n,e;

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
 cin>>n>>e;
 f(e)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
 }
 cout<<e<<endl;
 }
 return 0;
}

// Given a directed and connected graph with n nodes. If there is an edge from u to v then u depends on v.
