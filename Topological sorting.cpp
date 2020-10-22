// dfs-Topological sorting

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


//  Kahn’s algorithm for Topological Sorting(bfs)

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


// Alien Dictionary

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
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/


const ll N=26;
vector<ll>adj[N];
bool vis[N];
unordered_set<ll>ss;
stack<ll>stk;

void dfs(ll u)
{
 vis[u]=1;
 for(auto xx:adj[u])
 {
  if(!vis[xx])
    dfs(xx);
 }
 stk.push(u);
}


int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  string dict[n];
  rep(i,0,n)
   cin>>dict[i];
  for(ll i=0;i<n-1;i++)
  {
   string word1=dict[i],word2=dict[i+1];
   for(ll j=0;j<min(word1.length(),word2.length());j++)
   {
    if(word1[j]!=word2[j])
    {
     adj[word1[j]-'a'].pb(word2[j]-'a');
     ss.insert(word1[j]-'a');
     ss.insert(word2[j]-'a');
     break;
    }
   }
  }
  mem(vis,0);
  for(ll i=0;i<N;i++)
  {
   if(!vis[i] && ss.find(i)!=ss.end())
     dfs(i);
  }
  string ans="";
  while(!stk.empty())
  {
   ans+=(char)(stk.top()+'a');
   stk.pop();
  }
  cout<<ans<<"\n";
  rep(i,0,N)
   adj[i].clear();
  ss.clear();

 }
 return 0;
}


// kosaraju

#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define HRX 1e18
#define INF 1000000007
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;

const ll N=2*100001;
vector<ll>adj1[N];
vector<ll>adj2[N];
bool vis[N];
stack<ll>s;
ll n,e;


void dfs2(ll u)
{
  vis[u]=1;
  cout<<u<<" ";
  for(ll i=0;i<adj2[u].size();i++)
  {
    ll v=adj2[u][i];
    if(!vis[v])
       dfs2(v);
  }
}

void dfs1(ll u)
{
  vis[u]=1;
  for(ll i=0;i<adj1[u].size();i++)
  {
    ll v=adj1[u][i];
    if(!vis[v])
       dfs1(v);
  }
  s.push(u);
}

void kosaraju(ll src)
{
  mem(vis,0);
  for(ll i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      dfs1(i);
    }
  }
  mem(vis,0);

  while(!s.empty())
  {
    ll x=s.top();
    s.pop();
    if(!vis[x])
    {

      dfs2(x);
      cout<<"\n";
    }

  }

  f(N)
  {
    adj1[i].clear();
    adj2[i].clear();
  }
}

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
    adj1[x].pb(y);
    adj2[y].pb(x);
  }
  kosaraju(1);
  }
  return 0;
}


/*O(V+E)
https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
https://www.hackerrank.com/contests/world-codesprint-11/challenges/hackerland/problem
https://www.spoj.com/problems/CAPCITY/
https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/
https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/joker-is-back/
https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/magical-islands/
https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/monk-and-his-unique-trip/
http://codeforces.com/contest/999/problem/E
http://codeforces.com/contest/505/problem/D
https://codeforces.com/contest/118/problem/E
*/

