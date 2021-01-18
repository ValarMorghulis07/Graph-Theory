// dijkstra

#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
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
vector<pair<ll,ll>>adj[N];
ll n,e;

void printPath(ll parent[],ll j)
{

    // Base Case : If j is source
    if (parent[j] ==-1)
        return;

    printPath(parent, parent[j]);
    cout<<j<<" ";
}
void shortestpath(ll src)
{
   priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
   ll dist[n];
   ll parent[n];
   bool vis[n]; // must use it (CSES TC without it gives TLE)
   mem(vis,0);
   for(ll i=1;i<=n;i++)
    {
        dist[i]=INF;
        parent[i]=-1;
    }
   pq.push(m_p(0,src));
   dist[src]=0;
   while(!pq.empty())
   {
       ll u=pq.top().second;
       pq.pop();
       if(vis[u])continue;
       vis[u]=1;
       for(auto x:adj[u])
       {
           ll v=x.first;
           ll weight=x.second;
           if(dist[v]>dist[u]+weight)
           {
               dist[v]=dist[u]+weight;
               parent[v]=u;
               pq.push(m_p(dist[v],v));

           }
       }
   }
   for(ll i=1;i<=n;i++)
   {
       cout<<"\n";
       cout<<i<<" "<<dist[i]<<" "<<src<<" ";
       printPath(parent, i);
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
            ll x,y,w;
            cin>>x>>y>>w;
            adj[x].pb(m_p(y,w));
            adj[y].pb(m_p(x,w));
        }
        ll src;
        cin>>src;
        shortestpath(src);
    }
    return 0;
}

/*O(V + E log V)
https://www.hackerearth.com/problem/algorithm/dijkstras-cost/
https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/booze-first-76e979dd/
https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/ways/
https://www.hackerearth.com/problem/algorithm/dijkstras/
https://www.hackerrank.com/challenges/dijkstrashortreach/problem
https://www.hackerrank.com/contests/cs526-basics/challenges/dijkstrashortreach
https://www.codechef.com/problems/KNGPRB
https://www.codechef.com/problems/INLO33
https://www.codechef.com/problems/STRGRA
https://www.codechef.com/problems/MCO16205
https://codeforces.com/contest/20/problem/C
http://codeforces.com/contest/230/problem/D
https://codeforces.com/problemset/problem/144/D
https://codeforces.com/contest/96/problem/D
*/

// prims

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
vector<pair<ll,ll>>adj[N];
ll n,e;

void mst(ll root)
{
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
    ll dist[n],parent[n],inMST[n];
    for(ll i=0;i<n;i++)
    {
       dist[i]=HRX;
       parent[i]=-1;
       inMST[i]=0;
    }
    pq.push(m_p(0,root));
    dist[root]=0;
    ll cost=0;
    while(!pq.empty())
    {
        ll u=pq.top().second;
        ll uv=pq.top().first;
        pq.pop();
        if(inMST[u]==1)
            continue;
        cost=cost+uv;
        inMST[u]=1;

        for(auto x:adj[u])
        {
           ll v=x.first;
           ll weight=x.second;
           if(inMST[v]==0 && dist[v]>weight)
           {
               dist[v]=weight;
               parent[v]=u;
               pq.push(m_p(dist[v],v));

           }
        }

    }
    for(ll i=0;i<n;i++)
    {
        cout<<parent[i]<<" "<<i<<endl;
    }
    cout<<cost<<endl;

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
        ll x,y,w;
        cin>>x>>y>>w;
        adj[x].pb(m_p(y,w));
        adj[y].pb(m_p(x,w));
    }
    ll root;
    cin>>root;
    mst(root);
    }
    return 0;

}
/*O(VlogV + ElogV)==ElogV
https://www.hackerrank.com/challenges/primsmstsub/problem
https://www.hackerrank.com/challenges/minimum-mst-graph/problem
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/pilgrims-and-portals/
https://www.hackerearth.com/challenges/competitive/code-monk-minimum-spanning-tree/algorithm/check-it/
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/maximum-spanning-tree/
https://www.codechef.com/problems/CHEFGAME
https://www.codechef.com/problems/STMINCUT
https://codeforces.com/contest/609/problem/E
*/

// kruskal

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
pair<ll,pair<ll,ll>>adj[N];
ll id[N];
ll n,e;

void initialize()
{
    f(N)
    {
      id[i]=i;
    }
}


ll root(ll z)
{
    while(id[z]!=z)
    {
        id[z]=id[id[z]];
        z=id[z];
    }
    return z;
}


void union1(ll x,ll y)
{
  ll u=root(x);
  ll v=root(y);
  id[u]=id[v];
}


void kruskal()
{
    ll cost=0;
    for(ll i=0;i<e;i++)
    {
        ll x=adj[i].second.first;
        ll y=adj[i].second.second;
        ll weight=adj[i].first;
        if(root(x)!=root(y))
        {
            cost=cost+weight;
            union1(x,y);
        }
    }
    cout<<cost<<endl;

}


int main()
{
    hs;
    ll t;
    cin>>t;
    f(t)
    {
      initialize();
      cin>>n>>e;
      f(e)
      {
        ll x,y,w;
        cin>>x>>y>>w;
        adj[i]=m_p(w,m_p(x,y));
      }
      sort(adj,adj+e);
      kruskal();
    }
    return 0;

}


/*O(ElogE)
https://www.hackerrank.com/challenges/kruskalmstrsub/problem
https://www.spoj.com/problems/MST/
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/mr-president/
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/jhakaas-and-mars-trip/
https://www.codechef.com/LTIME43/problems/MSTQS
https://www.codechef.com/problems/COALSCAM
https://codeforces.com/contest/160/problem/D
https://codeforces.com/contest/125/problem/E
https://codeforces.com/contest/908/problem/F
https://codeforces.com/contest/76/problem/A
https://codeforces.com/problemset/problem/598/D
https://codeforces.com/problemset/problem/744/A
*/

// bellman ford

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
pair<ll,pair<ll,ll>>adj[N];
ll n,e;


void belford(ll start)
{
    ll dist[n];
    for(ll i=0;i<n;i++)
    {
       dist[i]=INT_MAX;
    }
    dist[start]=0;
    for(ll i=1;i<=n-1;i++)
    {
        for(ll j=0;j<e;j++)
        {
            ll u=adj[j].second.first;
            ll v=adj[j].second.second;
            ll weight=adj[j].first;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
            }
        }
    }
       ll ff=0;
       for(ll j=0;j<e;j++)
        {
            ll u=adj[j].second.first;
            ll v=adj[j].second.second;
            ll weight=adj[j].first;
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight) // from which node u are updating that should not be INFINITY.
            {
              cout<<"graph contains negative weight cycle"<<endl;
              ff=1;
              break;
            }
        }
        if(ff==0)
        {
          f(n)
          {
              cout<<i<<" "<<dist[i]<<endl;
          }
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
            ll x,y,w;
            cin>>x>>y>>w;
            adj[i]=m_p(w,m_p(x,y));

        }
        ll src;
        cin>>src;
        belford(src);
    }
    return 0;
}

/*O(VE)
https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/monks-business-day/description/
https://www.codechef.com/problems/BESTPATH
https://www.codechef.com/problems/GUESSAGE
https://www.codechef.com/problems/KGP16J
https://www.codechef.com/problems/AVGSHORT
http://codeforces.com/problemset/gymProblem/100923/B
https://codeforces.com/problemset/problem/295/B
*/

// floydd warshall

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
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=505;
ll dist[N][N];
ll n,e,q;

void floydd()
{
 rep(k,1,n+1)
  rep(i,1,n+1)
    rep(j,1,n+1)
      if(dist[i][j]>dist[i][k]+dist[k][j])
         dist[i][j]=dist[i][k]+dist[k][j];

}

int main()
{
 hs;
 cin>>n>>e>>q;
 rep(i,0,N)
  rep(j,0,N)
    dist[i][j]=ESP;
 rep(i,0,N)
   dist[i][i]=0;
 rep(i,0,e)
 {
  ll x,y,w;
  cin>>x>>y>>w;
  dist[x][y]=min(dist[x][y],w); // if(multiple edges are there)
  dist[y][x]=min(dist[y][x],w);
 }
 floydd();
 while(q--)
 {
  ll x,y;
  cin>>x>>y;
  if(dist[x][y]!=ESP)
    cout<<dist[x][y]<<"\n";
  else
    cout<<"-1"<<"\n";
 }
 return 0;
}

// single souce longest path (bellford) --> // https://cses.fi/problemset/task/1673

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
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=5010;
pair<ll,pair<ll,ll>>adj[N];
vector<ll>adj1[N],adj2[N];
bool vis1[N],vis2[N];
ll n,e;

void dfs1(ll u)
{
 vis1[u]=1;
 for(auto xx:adj1[u])
 {
  if(!vis1[xx])
    dfs1(xx);
 }
}

void dfs2(ll u)
{
 vis2[u]=1;
 for(auto xx:adj2[u])
 {
  if(!vis2[xx])
    dfs2(xx);
 }
}

void bellford(ll src)
{
 ll dist[n+1];
 rep(i,0,n+1)
  dist[i]=ESP;
 dist[src]=0;
 bool ff=0;
 rep(i,0,n)
 {
  rep(j,0,e)
  {
   ll u=adj[j].ss.ff;
   ll v=adj[j].ss.ss;
   ll w=adj[j].ff;
   if(dist[u]!=ESP && dist[v]>dist[u]+w)
   {
    dist[v]=dist[u]+w;
    if(i==n-1 && vis1[v] && vis2[v]) // if relaxation in last step and v is visited in dfs from both (1 && n) means there is a postive cycle.
    {
     ff=1;
     break;
    }
   }
  }
 }
 if(ff)
    cout<<"-1";
 else
    cout<<-dist[n];
}

int main()
{
 hs;
 cin>>n>>e;
 rep(i,0,e)
 {
  ll x,y,w;
  cin>>x>>y>>w;
  adj[i]=m_p(-w,m_p(x,y));
  adj1[x].pb(y);
  adj2[y].pb(x);

 }
  mem(vis1,0);
  mem(vis2,0);
  dfs1(1);
  dfs2(n);
  bellford(1);
  return 0;
}

/*

If there is a positive weight cycle which comprises  src && dest then you have to print -1 in that case.
3 4
2 1 4
1 2 -3
1 3 2
--> here answer is -1 in SSLP.

But in this case,
5 5
2 3 4
3 4 -3
4 2 6
3 1 2
1 5 3

--> here answer is not -1 in SSLP.
*/

