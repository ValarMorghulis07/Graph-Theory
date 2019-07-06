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


/*
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
