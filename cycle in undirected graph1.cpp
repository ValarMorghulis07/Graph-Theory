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

const ll N=2*10001;
vector<ll>adj[N];
bool vis[N];
ll m,n,ff;
ll dfs(ll u,ll parent)
{
    if(!vis[u])
    {
        vis[u]=true;
        for(ll i=0;i<adj[u].size();i++)
        {
            ll v=adj[u][i];
            if(v == parent)
                continue;
            else
              ff=ff || dfs(v,u);

        }
        return ff;
    }
    else
      return 1;

}

int main()
{
	hs;
	ll t;
	cin>>t;
	f(t)
	{
    cin>>n>>m;
    f(m)
    {
        int a,b;
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
     for(ll i=1;i<=n;i++)
     {
         ff=0;
         mem(vis,0);
         ll zz=0;
         zz=dfs(i,-1);
         if(zz==1)
         {
             cout<<"YES"<<endl;
             break;
         }
         else if(zz==0 && i==n)
         {
            cout<<"NO"<<endl;
         }

     }
     f(N)
     {
         adj[i].clear();
     }
	}




	return 0;
}
