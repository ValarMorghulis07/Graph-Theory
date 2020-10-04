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


const ll N=2e5+5;
vector<ll>adj[N];
ll col[N];
ll n,e,ff;
stack<ll>stk;

void dfs(ll u)// Topological sorting for Directed Acyclic Graph (DAG)
{
 col[u]=1;
 for(auto xx:adj[u])
 {
  if(col[xx]==1)
    ff=1;
  if(col[xx]==0)
    dfs(xx);
 
 }
 col[u]=2;
 stk.push(u);
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  cin>>n>>e;
  rep(i,0,e)
  {
   ll x,y;
   cin>>x>>y;
   adj[x].pb(y);
  }
  ff=0;
  rep(i,0,N)
   col[i]=0;
  rep(i,0,n)
  {
   if(col[i]==0)
    dfs(i);
  }
  if(ff==1)
    cout<<"No Topo Sort";
  else
  {
   while(!stk.empty())
   {
    ll xx=stk.top();
    stk.pop();
    cout<<xx<<" ";
   }
  }
  cout<<"\n";
  rep(i,0,N)
   adj[i].clear();

 }
 return 0;
}

/*
2
6 6
5 2
5 0
4 0
4 1
2 3
3 1
5 5
0 1
1 2
2 0
1 3
3 4
*/
// The first vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).
