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

const ll N=2*100001;
vector<ll>adj[N];
bool vis[N];
ll n,e;
stack<ll>s;

void dfs(ll u)
{
  vis[u]=1;
  f(adj[u].size())
  {
    ll v=adj[u][i];
    if(!vis[v])
        dfs(v);
  }
  s.push(u);
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
    }

    mem(vis,0);
    for(ll i=1;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end(),greater<ll>());
    }
    for(ll i=n;i>=1;i--)
    {
      if(!vis[i])
      {
        dfs(i);
      }
    }
    while(!s.empty())
    {
      cout<<s.top()<<" ";
      s.pop();
    }
    cout<<"\n";

  }
  return 0;
}

/*
https://practice.geeksforgeeks.org/problems/topological-sort/1
https://www.spoj.com/problems/TOPOSORT/
https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/
https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/find-the-array-616201fd/
https://www.hackerrank.com/contests/101hack40/challenges/next-topological-sorting
*/
