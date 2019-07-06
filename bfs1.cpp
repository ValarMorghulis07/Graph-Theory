#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mem(dp,a)           memset(dp,a,sizeof dp)
#define rep(i,a,b)          for(ll i=a;i<b;i++)
#define repb(i,a,b)         for(ll i=a;i>=b;i--)
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define tr(c,it)            for(auto const &it : c)
#define xlr8                ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sz(c)               (c).size()
#define all(c)              (c).begin(),(c).end()
#define sl(a)               scanf("%lld",&a);
#define TH                  1000
#define F                   first
#define S                   second
ll MOD=pow(10,9)+7;
ll INF=1e18+10;


const int N=5000;
vector <int> adj[N];


void bfs(int a)
{

    bool vis[N];
    rep(i,0,N)
    {
        vis[i]=false;
    }
    queue <int> q;
    if(!vis[a])
    vis[a]=true;
    q.push(a);

    while(!q.empty())
    {
        int b=q.front();
        cout<<b<<" ";
        q.pop();
        for(auto it : adj[b])
        {
            if(!vis[it])
            vis[it]=true,
            q.push(it);
        }


    }
    rep(i,0,5000)
    {
      adj[i].clear();
    }


}

int main()
{
    int t;
    cin>>t;
  for(int i=0;i<t;i++)
    {
    int m;
    cin>>m; // number of edges assuming (number of nodes<=5000)
    int directed;
    cin>>directed;


    if(directed)
    {
      rep(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);

    }

    }
    else
    {
    rep(i,0,m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    }

    //considering 1 is always a node in the graph
    int start;
    cin>>start;
    bfs(start);
    }
    return 0;
}
/*
https://codeforces.com/problemset/problem/59/E
*/
