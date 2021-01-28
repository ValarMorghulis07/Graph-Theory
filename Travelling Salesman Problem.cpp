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

const ll N=25;
ll a[N][N],dp[1LL<<N][N];
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
 if(mask==(1<<n)-1) // if all nodes have been visited finally add cost to return to source node.
    return a[pos][0]; 
 if(dp[mask][pos]!=-1) // if some node have already been visited no need to calculate it again (look up)
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
  cout<<tsp(1,0)<<endl; // here mask is 1 b'coz we are starting from node 0
 }
 return 0;

}

// Problem link: https://cses.fi/problemset/task/1690/

// Hamiltonian Flights --> we have to find no. of hamiltonian paths from 1 to n.

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

const ll N=22;
vector<ll>adj[N];
ll dp[1LL<<N][N];
ll n,e;

ll doit(ll u,ll mask) // recursion + bitmask (O((n!))
{
 if(mask==((1LL<<n)-1)) // if we have reached the last city then add one path
    return 1;
 else if(u==n-1) // This is mainly done if the upper (if case) didn't run and this runs means although it has reached city n-1 but not visited them all.
    return 0;
 ll ans=0;
 for(auto city:adj[u])
 {
  if(mask & (1LL<<city)) // already visited city
    continue;
  ans+=doit(city,mask | (1LL<<city));
  ans%=FCB;
 }
 return ans;
}

int doit(int u,int mask) // dp+bitmask O(2^n*n) --> for this particular question use int in place of ll.
{
 if(mask==(1LL<<n)-1) // if we have reached the last city then add one path
    return 1;
 else if(u==n-1) // This is mainly done if the upper (if case) didn't run and this runs means although it has reached city n-1 but not visited them all.
    return 0;
 if(dp[mask][u]!=-1)
    return dp[mask][u];
 int ans=0;
 for(auto city:adj[u])
 {
  if(mask & (1LL<<city)) // already visited city
    continue;
  ans+=doit(city,mask | (1LL<<city));
  ans%=FCB;
 }
 return (dp[mask][u]=ans);
}


int main()
{
 hs;
 cin>>n>>e;
 rep(i,0,e)
 {
  ll x,y;
  cin>>x>>y;
  x--;y--;
  adj[x].pb(y);
 }
 rep(i,0,1LL<<n)
  rep(j,0,n)
    dp[i][j]=-1; // instead of mem(dp,-1) use loop,b'coz it gives wrong answer sometimes
 cout<<doit(0,1); // since we have to start from city 0
 return 0;

}


// Hamiltonian Path anad Cycle

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
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=11;
vector<ll>adj[N];
bool vis[N];
vector<ll>path;
ll n,e;

bool HamPath(ll u)
{
 if(path.size()==n)
     return true;
 for(auto xx:adj[u])
 {
  if(!vis[xx])
  {
   vis[xx]=1;
   path.pb(xx);
   if(HamPath(xx))
    return true;
   vis[xx]=0;
   path.pop_back();
  }
 }
 return false;
}

int main()
{
 hs;
 cin>>n>>e;
 map<pair<ll,ll>,bool>mp;
 rep(i,0,e)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
  mp[{x,y}]=1;
  mp[{y,x}]=1;
 }
 bool ff=0;
 rep(i,1,n+1) // start from each node
 {
  path.clear();
  mem(vis,0);
  path.pb(i);
  vis[i]=1;
  if(HamPath(i))
  {
   cout<<"Hamiltonian Path is there from "<<i<<"\n";
   ll zz=path.back();
   if(mp[{zz,i}]) // if there is edge from last node in H.path to source node,then it contains H.Cycle
   {
    cout<<"Hamiltonian Cycle are:"<<"\n";
    for(auto xx:path)
        cout<<xx<<" ";
    cout<<i<<"\n";
   }
  }
 }
 return 0;

}


