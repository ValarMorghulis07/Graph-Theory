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


/*
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
