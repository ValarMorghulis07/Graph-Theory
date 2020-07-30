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
ll in[N];
ll n,e;
vector<ll>vv;

void bfs()
{
 queue<ll>q;
 rep(i,0,n)
 {
  if(in[i]==0)
    q.push(i);
 }
 ll cnt=0;
 while(!q.empty())
 {
  ll u=q.front();
  q.pop();
  vv.pb(u);
  for(auto xx:adj[u])
  {
   if(--in[xx]==0)
    q.push(xx);
  }
  cnt++;
 }
 if(cnt!=n)
    cout<<"No Topo sort";
 else
 {
  rep(i,0,n)
   cout<<vv[i]<<" ";
 }
 cout<<"\n";
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  cin>>n>>e;
  rep(i,0,N)
   in[i]=0;
  rep(i,0,e)
  {
   ll x,y;
   cin>>x>>y;
   adj[x].pb(y);
   in[y]++;
  }
  bfs();
  rep(i,0,N)
   adj[i].clear();
  vv.clear();
 }
 return 0;

}

// A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
