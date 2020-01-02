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
char ch[N][N];
bool vis[N][N];
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
ll m,n;

void dfs1(ll x,ll y,char cc)
{
 if(!vis[x][y])
 {
  vis[x][y]=1;
  ch[x][y]=cc;
  for(ll i=0;i<4;i++)
  {
   ll xx=x+dir[i][0];
   ll yy=y+dir[i][1];
   if(xx>=0 && xx<m && yy>=0 && yy<n && !vis[xx][yy] && ch[xx][yy]=='O')
   {
    ch[xx][yy]=cc;
    dfs1(xx,yy,cc);
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
  mem(vis,0);
  f(m)
  {
   r(n)
   {
    cin>>ch[i][j];
   }
  }
  for(ll i=0;i<n;i++)
  {
   if(ch[0][i]=='O')
    dfs1(0,i,'Y');
  }
  for(ll i=0;i<n;i++)
  {
   if(ch[m-1][i]=='O')
    dfs1(m-1,i,'Y');
  }
  for(ll i=0;i<m;i++)
  {
   if(ch[i][0]=='O')
    dfs1(i,0,'Y');
  }
  for(ll i=0;i<m;i++)
  {
   if(ch[i][n-1]=='O')
    dfs1(i,n-1,'Y');
  }
  mem(vis,0);
  f(m)
  {
   r(n)
   {
    if(ch[i][j]=='O')
      dfs1(i,j,'X');
   }
  }
  f(m)
  {
   r(n)
   {
    if(ch[i][j]=='Y')
     cout<<"O"<<" ";
    else
     cout<<ch[i][j]<<" ";
   }
   cout<<"\n";
  }

 }
 return 0;
}

/*
3
1 5
X O X O X
3 3
X X X
X O X
X X X
6 6
X O X X X X
X O X X O X
X X X O O X
O X X X X X
X X X O X O
O O X O O O
*/

