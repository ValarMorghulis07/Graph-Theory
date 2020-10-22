// dfs


#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof dp)
#define INF 1000000007
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;

const ll N=10000;
vector<ll>adj[N];
bool vis[N];

void dfs(ll u) //Iterative
{
  stack<ll>stk;
  stk.push(u);
  while(!stk.empty())
  {
    u=stk.top();
    stk.pop();
    if(!vis[u])
    {
     cout<<u<<" ";
     vis[u]=1;
    }
    for(auto xx:adj[u])
    {
      if(!vis[xx])
          stk.push(xx);
    }
  }
}


void dfs(ll u) //Recursive
{
    vis[u]=true;
    cout<<u<<" ";
    for(auto x:adj[u])
    {
      if(!vis[x])
          dfs(x);
    }
}


int main()
{
    hs;
    ll t;
    cin>>t;
    f(t)
    {
        ll m;
        cin>>m;
        ll directed;
        cin>>directed;
        if(directed)
        {
          f(m)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);

        }
        }
        else
        {
        f(m)
        {
            ll x,y;
            cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        }
        ll start;
        cin>>start;
        mem(vis,0);
        dfs(start);


    }
    return 0;

}
/*
https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem
https://www.hackerrank.com/challenges/connected-cell-in-a-grid/problem
https://www.codechef.com/problems/SANTA2
*/


// bfs


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
ll n,e;

void bfs(ll u)
{
  mem(vis,0);
  ll dist[n+1];
  f(n+1)
  {
    dist[i]=HRX;
  }
  dist[u]=0;
  queue<ll>q;
  if(!vis[u])
    vis[u]=1;
  q.push(u);
  while(!q.empty())
  {
    ll u=q.front();
    cout<<u<<" ";
    q.pop();
    f(adj[u].size())
    {
     ll v=adj[u][i];
     if(!vis[v])
     {
       vis[v]=1;
       dist[v]=dist[u]+1;
       q.push(v);
     }
    }
  }

  for(ll i=2;i<n+1;i++)
  {
    cout<<dist[i]<<" ";
  }
   f(N)
  {
    adj[i].clear();
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
    adj[x].pb(y);
    adj[y].pb(x);
  }
  ll src;
  cin>>src;
  bfs(src);
  }
  return 0;
}


/*
https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/traffic-light-2-ee27ba45/
https://www.codechef.com/problems/DECUNI
https://codeforces.com/problemset/problem/59/E
https://codeforces.com/problemset/problem/1037/D
*/
*/
