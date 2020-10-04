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
