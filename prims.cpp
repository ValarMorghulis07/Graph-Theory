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
/*O(VlogV + ElogV)
https://www.hackerrank.com/challenges/primsmstsub/problem
https://www.hackerrank.com/challenges/minimum-mst-graph/problem
https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/pilgrims-and-portals/
https://www.hackerearth.com/challenges/competitive/code-monk-minimum-spanning-tree/algorithm/check-it/
https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/maximum-spanning-tree/
https://www.codechef.com/problems/CHEFGAME
https://www.codechef.com/problems/STMINCUT
https://codeforces.com/contest/609/problem/E
*/
