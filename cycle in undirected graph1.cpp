// cycle in undirected graph

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

// cycle in directed graph through coloring

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
ll color[N];
ll n,e,k,ff;


void dfs(ll u)
{
    color[u]=1;
    for(ll i=0;i<adj[u].size();i++)
    {
        ll v=adj[u][i];
        if(color[v]==1)
           ff=1
        if(color[v]==0)
          dfs(v);

    }
    color[u]=2;
   
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
    mem(color,0);
    
    for(ll i=1;i<=n;i++)
    {
        if(!color[i])
        {
            dfs(i);
            if(ff)
            {
              cout<<"Cycle found"<<endl;
              break;

            }
        }
    }
    if(ff==0)
    {
        cout<<"cycle not found"<<endl;
    }
    f(N)
    {
        adj[i].clear();
    }
    }
    return 0;
}

//O(V+E) and O(V)

/*
WHITE : Vertex is not processed yet. Initially, all vertices are WHITE.
GRAY: Vertex is being processed (DFS for this vertex has started, but not finished which means that all descendants (in DFS tree) of this vertex are not processed yet (or this vertex is in the function call stack)
BLACK : Vertex and all its descendants are processed. While doing DFS, 
if an edge is encountered from current vertex to a GRAY vertex, then this edge is back edge and hence there is a cycle.
*/

// cycle in directed graph

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
bool recstack[N];

ll n,e;
ll dfs(ll u)
{
    if(!vis[u])
    {
        vis[u]=1;
        recstack[u]=1;
        for(ll i=0;i<adj[u].size();i++)
        {
            ll v=adj[u][i];
            if(!vis[v] && dfs(v))
                return 1;
            else if(recstack[v])
            {

               return 1;
            }

        }

    }
    recstack[u]=0;
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
    vector<ll>vx;
    vector<ll>vy;
    f(e)
    {
        ll x,y;
        cin>>x>>y;
        vx.pb(x);
        vx.pb(y);
        adj[x].pb(y);
    }
    ll ff=0;
    r(e)
    {
    adj[vx[j]].remove(vy[j]);
    mem(vis,0);
    mem(recstack,0);

    for(ll i=1;i<=n;i++)
    {
    if(!vis[i])
    {
        if(!dfs(i))
        {
            cout<<"YES"<<endl;
            ff=1;
            break;
        }
        else
        {
            adj[vx[j]].pb(vy[j]);
        }
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

/*
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

// bipartite

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
ll n,e,ff=0;
bool vis[N];
bool color[N];

void isbipartite(ll u,bool col)
{
 vis[u]=1;
 color[u]=col;
 f(adj[u].size())
 {
  ll v=adj[u][i];
  if(!vis[v])
  {
    isbipartite(v,1-col);
  }
  else if(col==color[v])
     ff=1;
 }
}

int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  f(N)
   adj[i].clear();
   cin>>n>>e;
  f(e)
  {
    ll x,y;
    cin>>x>>y;
    adj[x].pb(y);
    adj[y].pb(x);
  }
  mem(vis,0);
  mem(color,0);
  ff=0;
  for(ll i=1;i<=n;i++)
  {
    if(!vis[i])
    {
      isbipartite(i,0);
      if(ff==1)
      {
        cout<<"Not bipartite"<<endl;
         break;
      }
    }
  }
  if(ff==0)
    cout<<"bipartite"<<endl;

 }
 return 0;
}

//O(V+E)



