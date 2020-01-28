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

/*O(E log V)
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
