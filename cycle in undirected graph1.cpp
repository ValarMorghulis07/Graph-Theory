#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define INF 1000000007
#define pb(x) push_back(x)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;

const ll N=2*100001;
vector<ll>adj[N];
bool vis[N];
ll n,e;
ll dfs(ll u,ll parent) //if there is an adjacent vertex which is visited but not the parent,then cycle exists--> means back edge is there
{
  vis[u]=1;
  for(ll i=0;i<adj[u].size();i++)
  {
      ll v=adj[u][i];
      if(!vis[v])
      {
          if(dfs(v,u))
            return 1;
      }
      else if(v!=parent)
        return 1;
  }
  return 0;
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
    ll ff=0;
    mem(vis,0);
    for(ll i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(dfs(i,-1))
            {
                 cout<<"YES"<<endl;
                 ff=1;
                 break;
            }

        }
    }
    if(ff==0)
        cout<<"NO"<<endl;
    f(N)
    {
        adj[i].clear();
    }
    }
    return 0;
}

/*o(V+E) and o(V)
https://www.spoj.com/problems/PT07Y/
https://www.spoj.com/problems/EPIC1304/
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/find-the-cycles/
https://www.hackerrank.com/contests/101hack23/challenges/devu-and-cycles-of-a-graph
https://www.codechef.com/problems/CHEFCYCL#
https://www.codechef.com/TESS2018/problems/FOUR#
https://codeforces.com/contest/915/problem/D
https://codeforces.com/contest/937/problem/D
https://codeforces.com/problemset/problem/263/D
*/


