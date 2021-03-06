// graphcoloring

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

const ll N=2*100007;
vector<ll>adj[N];
ll n,e;
set<ll>s;

void graphcoloring()
{
  ll color[n];
  color[0]=0;
  for(ll i=1;i<n;i++)
     color[i]=-1;
  bool available[n];
  mem(available,0);
  for(ll u=1;u<n;u++)
  {
    for(ll i=0;i<adj[u].size();i++)
    {
      ll v=adj[u][i];
      if(color[v]!=-1)
        available[color[v]]=1;
    }
    ll j;
    for(j=0;j<vec.size();j++)
    {
      if(available[j]==0)
        break;
    }
    color[u]=j;
    for(ll i=0;i<adj[u].size();i++)
    {
      ll v=adj[u][i];
      if(color[v]!=-1)
        available[color[v]]=0;
    }

  }
    for(ll i=0;i<n;i++)
    {
      s.insert(color[i]);
      cout<<i<<" "<<color[i]<<endl;
    }
    cout<<s.size()<<endl;
    f(N)
    {
        adj[i].clear();
    }
    s.clear();
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
    adj[x].pb(y);
    adj[y].pb(x);
  }
  graphcoloring();
  }
  return 0;
}

/*
https://practice.geeksforgeeks.org/problems/m-coloring-problem/0
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/color-the-graph/
https://www.hackerearth.com/problem/algorithm/coloring-problem/
https://www.hackerrank.com/challenges/coloring-grid/problem
https://www.hackerrank.com/challenges/kundu-and-tree/problem
https://www.spoj.com/problems/COLOR_CC/
https://www.spoj.com/problems/MTREECOL/
https://www.spoj.com/problems/BTCODE_G/
https://www.codechef.com/problems/PS18E
https://www.codechef.com/problems/KMHAMHA
https://www.codechef.com/DBYZ2013/problems/IITI11
https://www.codechef.com/CDCRFT14/problems/COPRIME
https://www.codechef.com/SNCKEL16/problems/COLTREE
https://www.codechef.com/problems/MACGUN
https://atcoder.jp/contests/abc133/tasks/abc133_e
https://codeforces.com/problemset/problem/662/B
https://codeforces.com/problemset/problem/183/C
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/approximate/edges-coloridx9ng/
https://code.google.com/codejam/contest/32010/dashboard#s=p2
*/


// distinct coloring till distanc1

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

const ll N=2*100007;
vector<ll>adj[N];
bool vis[N];
ll n,k;
ll ways[N];



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


    ll way=1;
    way=k;
    for(ll i=2;i<=n;i++)
    {
      way=(way*(k-1))%INF;
    }
    cout<<way<<endl;


  return 0;
}


// distinct coloring till distanc2

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

const ll N=2*100007;
vector<ll>adj[N];
bool vis[N];
ll n,k;
ll ways[N];

void dfs(ll u,ll level)
{
  vis[u]=1;
  if(level==0)
    ways[u]=k;
  ll j=(level==0) ? 1:2;
  for(ll i=0;i<adj[u].size();i++)
  {
    ll v=adj[u][i];
    if(!vis[v])
    {
     ways[v]=k-j;
     j++;
     dfs(v,1);
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
    ll way=1;
    for(ll i=1;i<=n;i++)
    {
      way=(way*ways[i])%INF;
    }
    cout<<way<<endl;


  return 0;
}

