/*

1.) Hamiltonian Paths--> which visits each node exactly once.

2.) Hamiltonian Cycle--> which visits each node exactly once and return to source node.

3.) TSP--> Minimum Cost hamiltonian Cycle.

*/

// TSP



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

const ll N=2*1007;
ll a[N][N];
ll dp[N][N];
ll n;

// recursion + bitmask (O(n!))
/*ll tsp(ll mask,ll pos)
{
 if(mask==(1<<n)-1)
    return a[pos][0];
 ll ans=HRX;
 for(ll city=0;city<n;city++)
 {
  if((mask & (1<<city))==0)
    ans=min(ans,a[pos][city] + tsp((mask|(1<<city)),city));
 }
 return ans;
}*/

// dp + bitmask (O(n*2^n))

ll tsp(ll mask,ll pos)
{
 if(mask==(1<<n)-1)
    return a[pos][0];
 if(dp[mask][pos]!=-1)
    return dp[mask][pos];
 ll ans=HRX;
 for(ll city=0;city<n;city++)
 {
  if((mask & (1<<city))==0) // if the city is not visited
    ans=min(ans,a[pos][city] + tsp((mask|(1<<city)),city)); // here (city is where we have to go and pos is where we are)
 }
 return (dp[mask][pos]=ans);
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
   }
  }
  for(ll i=0;i<(1<<n);i++)
    for(ll j=0;j<n;j++)
      dp[i][j]=-1;
  cout<<tsp(1,0)<<endl;
 }
 return 0;

}
