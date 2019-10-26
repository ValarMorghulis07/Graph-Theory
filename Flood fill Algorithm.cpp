#include<bits/stdc++.h>
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

const ll N=1007;
ll a[N][N];
ll m,n;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool vis[N][N];

void dfs(ll zz,ll x,ll y,ll z)
{
 if(!vis[x][y])
 {
  vis[x][y]=1;
  a[x][y]=z;
  for(ll i=0;i<4;i++)
  {
   ll xx=x+dir[i][0];
   ll yy=y+dir[i][1];
   if(xx>=0 && xx<m && yy>=0 && yy<n && a[xx][yy]==zz && !vis[xx][yy])
   {
    a[xx][yy]=z;
    dfs(zz,xx,yy,z);
   }
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
  cin>>m>>n;
  f(m)
  {
   r(n)
   {
    cin>>a[i][j];
    vis[i][j]=0;
   }
  }
  ll x,y,z;
  cin>>x>>y>>z;
  ll zz=a[x][y];
  dfs(zz,x,y,z);
  f(m)
  {
    r(n)
    {
     cout<<a[i][j]<<" ";
    }
    cout<<"\n";
  }
 }
 return 0;
}
