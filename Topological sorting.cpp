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
ll col[N];
//bool vis[N];
ll n,e,ff;
stack<ll>s;

void dfs(ll u,ll parent)
{
  vis[u]=1;
  color[u]=1;
  f(adj[u].size())
  {
    ll v=adj[u][i];
    if(color[v]==1)
       ff=1;
    if(color[v]==0)
        dfs(v,u);
  }
  color[u]=2;
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

    //mem(vis,0);
    ff=0;
    mem(color,0);
    for(ll i=1;i<=n;i++)
    {
      if(!vis[i])
      {
        dfs(i,-1);
      }
    }
    if(ff==1)
      cout<<"No Topo Sort";
    else
    {
       while(!s.empty())
    {
      cout<<s.top()<<" ";
      s.pop();
    }
    }
    cout<<"\n";

  }
  return 0;
}

/* O(V+E)
https://practice.geeksforgeeks.org/problems/topological-sort/1
https://www.spoj.com/problems/TOPOSORT/
https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/lonelyisland-49054110/
https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/oliver-and-the-game-3/
https://www.hackerearth.com/practice/algorithms/graphs/topological-sort/practice-problems/algorithm/find-the-array-616201fd/
https://www.hackerrank.com/contests/101hack40/challenges/next-topological-sorting
*/
