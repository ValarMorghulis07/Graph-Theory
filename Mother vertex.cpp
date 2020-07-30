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

const int N=2*10001;
 bool vis[N];
 int mother;
 void dfs(int u,vector<int> adj[])
 {
   vis[u]=1;
   for(int i=0;i<adj[u].size();i++)
   {
      int v=adj[u][i];
      if(!vis[v])
         dfs(v,adj);
   }
 }

 void dfs1(int u,vector<int> adj[])
 {
   vis[u]=1;
   for(int i=0;i<adj[u].size();i++)
   {
      int v=adj[u][i];
      if(!vis[v])
         dfs1(v,adj);
   }
 }
int findMother(int V, vector<int> adj[])
{
  memset(vis,0,sizeof(vis));
  for(int i=0;i<V;i++)
  {
     if(!vis[i])
     {
        dfs(i,adj);
        mother=i;
     }
  }
  memset(vis,0,sizeof(vis));
  dfs1(mother,adj);
  int ff=0;
  for(int i=0;i<V;i++)
  {
    if(vis[i]!=1)
    {
      ff=1;
      break;
    }
  }
  if(ff==0)
    return mother;
  else if(ff==1)
    return -1;


}

// There can be more than one mother vertices in a graph. We need to output anyone of them
// If there exist mother vertex (or vertices), then one of the mother vertices is the last finished vertex in DFS.
