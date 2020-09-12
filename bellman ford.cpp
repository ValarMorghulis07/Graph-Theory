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
            if(dist[u]!=INT_MAX && dist[v]>dist[u]+weight) // from wg=hich node u are updating that should not be INFINITY.
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
