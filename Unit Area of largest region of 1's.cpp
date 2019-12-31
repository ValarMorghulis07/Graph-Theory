#include <bits/stdc++.h>
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

const ll N=1e3+7;
ll a[N][N];
bool vis[N][N];
ll m,n;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
ll cnt,maxx;

void dfs(ll c,ll d)
{
 if(!vis[c][d])
 {
  vis[c][d]=1;
  for(ll i=0;i<8;i++)
  {
   ll xx=c+dir[i][0];
   ll yy=d+dir[i][1];
   if(xx>=0 && xx<m && yy>=0 && yy<n && !vis[xx][yy])
   {
    if(a[xx][yy]-a[c][d]==0)
    {
    cnt++;
    maxx=max(maxx,cnt);
    dfs(xx,yy);
    }
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
  maxx=INT_MIN;

  f(m)
  {
   r(n)
   {
    cin>>a[i][j];
    vis[i][j]=0;
   }
  }
  f(m)
  {
   r(n)
   {
    if(a[i][j]==1)
    {
     if(!vis[i][j])
     {
     cnt=0;
     dfs(i,j);
     }
    }
   }
  }
  cout<<max((ll)0,maxx)<<endl;

 }
 return 0;
}
