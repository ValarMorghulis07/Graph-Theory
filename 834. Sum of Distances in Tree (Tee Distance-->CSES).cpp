// 834. Sum of Distances in Tree (Tree distance - II -->CSES)



const int N=1e4+7;
vector<int>adj[N];
    

class Solution {
public:
    vector<int>subtree,dist;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
    {
     subtree.assign(N,1);
     dist.assign(N,0);
     for(int i=0;i<edges.size();i++)
     {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
     }
     dfs(0,-1);
     dfs1(0,-1);
     for(int i=0;i<N;i++)
         adj[i].clear();
     return dist;
     
    }
    
     void dfs(int u,int par)
    {
     for(auto xx:adj[u])
     {
      if(xx==par)
          continue;
      dfs(xx,u);
      subtree[u]+=subtree[xx]; // cnt subtrees in node u
      dist[u]+=dist[xx]+subtree[xx]; // add sum of distances from node node u to all downward nodes --> if u r just asked to do the same thing just below the node u,then this is only sufficient.
      // (here in dist[u] subtree[xx] is added b'coz the edge which connects u to xx will addup distance in u due to all its subtree.)
     }
    }
    
    void dfs1(int u,int par) // these are tree reroorting techniques to count on upper nodes wrt to each node
    {
     for(auto xx:adj[u])
     {
      if(xx==par)
          continue;
      dist[xx]=dist[u]-subtree[xx]+(subtree.size()-subtree[xx]); // here (dist[u]-subtree[xx] --> it means we are just removing contibution of xx from u) and (subtree.size()-subtree[xx]-->like in the upper case we added subtree[xx] ,here also we are doing the same by removing subtree of xx from xx) 
      dfs1(xx,u);
     }
    }
};

// Tree Distance - I (CSES)

/*
You are given a tree consisting of n nodes.
Your task is to determine for each node the maximum distance to another node.
*/

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
int FCB=1e9+7;
ll prime=119;
ll dir[][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=2e5+7;
vector<ll>adj[N];
ll dist[N][2];
ll n,node,val=-1;

void dfs(ll u,ll par,ll idx,ll lev)
{
 dist[u][idx]=lev;
 if(dist[u][idx]>=val)
 {
  val=dist[u][idx];
  node=u;
 }
 for(auto xx:adj[u])
 {
  if(xx!=par)
     dfs(xx,u,idx,lev+1);
 }
}

int main()
{
 hs;
 cin>>n;
 rep(i,0,n-1)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
 }
 dfs(1,0,0,0); // finding the deepest node from root(farthest from root)
 val=-1;
 dfs(node,0,0,0); // running dfs form deepest node 1
 val=-1;
 dfs(node,0,1,0); // running dfs form deepest node 2
 rep(i,1,n+1)
  cout<<max(dist[i][0],dist[i][1])<<" "; // printing the max distance of node from both deepest node
 return 0;

}

