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

const ll N=30;
bool vis[N][N];
ll n,m;
ll dir[][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{-1,2},{1,-2},{-1,-2}};


ll bfs(ll sx,ll sy,ll dx,ll dy)
{
 ll dist[n+1][m+1];
 f(n+1)
 {
  r(m+1)
  {
   dist[i][j]=HRX;
   vis[i][j]=0;
  }
 }
 queue<pair<ll,ll>>q;
 if(!vis[sx][sy])
    vis[sx][sy]=1;
 q.push(m_p(sx,sy));
 dist[sx][sy]=0;
 while(!q.empty())
 {
  pair<ll,ll>temp=q.front();
  q.pop();
  for(ll i=0;i<8;i++)
  {
    ll tx=temp.first;
    ll ty=temp.second;
    ll xx=tx+dir[i][0];
    ll yy=ty+dir[i][1];
    if(!vis[xx][yy] && xx>=0 && yy>=0 && xx<n && yy<m)
    {
     vis[xx][yy]=1;
     dist[xx][yy]=dist[tx][ty]+1;
     q.push(m_p(xx,yy));
    }
  }
 }
 if(dist[dx][dy]!=HRX)
    cout<<dist[dx][dy]<<endl;
 else
    cout<<"-1"<<endl;

}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>n>>m;
  ll sx,sy,dx,dy;
  cin>>sx>>sy>>dx>>dy;
  sx--;
  sy--;
  dx--;
  dy--;

  if(sx==dx && sy==dy)
    cout<<"0"<<endl;
  else
    bfs(sx,sy,dx,dy);

 }
 return 0;
}
