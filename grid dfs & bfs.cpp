// 695. Max Area of Island

const int N=55;
bool vis[N][N];
int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
int maxx,cnt;
class Solution {
public:
    void dfs(vector<vector<int>>& grid,int m,int n,int x,int y)
    {
     for(int i=0;i<4;i++)
     {
      int xx=x+dir[i][0];
      int yy=y+dir[i][1];
      if(xx>=0 && xx<m && yy>=0 && yy<n && !vis[xx][yy] && grid[xx][yy]==1)
      {
       cnt++;
       maxx=max(maxx,cnt);
       vis[xx][yy]=1;
       dfs(grid,m,n,xx,yy);
      }
     }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
     int m=grid.size();
     int n=grid[0].size();
    
     maxx=0,cnt=0;
     memset(vis,0,sizeof(vis));
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(!vis[i][j] && grid[i][j]==1)
       {
         cnt=1;
         vis[i][j]=1;
         dfs(grid,m,n,i,j);
       }
      }
     }
     return max(maxx,cnt);
     
    }
};

// 733. Flood Fill

const int N=55;
bool vis[N][N];
int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};


class Solution {
public:
    void dfs(vector<vector<int>>& image,int m,int n,int x,int y,int pp,int qq)
    {
     for(int i=0;i<4;i++)
     {
      int xx=x+dir[i][0];
      int yy=y+dir[i][1];
      if(xx>=0 && xx<m && yy>=0 && yy<n && !vis[xx][yy] && image[xx][yy]==pp)
      {
       image[xx][yy]=qq;
       vis[xx][yy]=1;
       dfs(image,m,n,xx,yy,pp,qq);
      }
     }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
     int m=image.size();
     int n=image[0].size();
     memset(vis,0,sizeof(vis));
     if(image[sr][sc]==newColor)
         return image;
    int old=image[sr][sc];
    image[sr][sc]=newColor;
    dfs(image,m,n,sr,sc,old,newColor);
    return image;
    }
};

// 130. Surrounded Regions

const int N=1e3+7;
bool vis[N][N];
int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
int m,n;


class Solution {
public:
    
    void dfs(vector<vector<char>>& board,int x,int y)
    {
     for(int i=0;i<4;i++)
     {
      int xx=x+dir[i][0];
      int yy=y+dir[i][1];
      if(xx>=0 && xx<m && yy>=0 && yy<n && !vis[xx][yy] && board[xx][yy]=='O')
      {
       vis[xx][yy]=1;
       board[xx][yy]='#';
       dfs(board,xx,yy);
      }
     }
    }
    void solve(vector<vector<char>>& board) 
    {
     m=board.size();
     if(m==0)
         return ;
     n=board[0].size();
     memset(vis,0,sizeof(vis));
     vector<pair<int,int>>vv;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if((i==0 || j==0 || i==m-1 || j==n-1) && board[i][j]=='O')
           vv.push_back(make_pair(i,j));
      }
     }
     for(int i=0;i<vv.size();i++)
     {
      int x=vv[i].first;
      int y=vv[i].second;
      if(board[x][y]=='O')
      {
       board[x][y]='#';
       dfs(board,x,y);
      }
     }
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(board[i][j]=='#')
           board[i][j]='O';
       else if(board[i][j]=='O')
           board[i][j]='X';
      }
     }
     
    }
};

// 200. Number of Islands

const int N=505;
bool vis[N][N];
int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};



class Solution {
public:
    void dfs(vector<vector<char>>& grid,int m,int n,int x,int y)
    {
     for(int i=0;i<4;i++)
     {
      int xx=x+dir[i][0];
      int yy=y+dir[i][1];
      if(xx>=0 && xx<m && yy>=0 && yy<n && !vis[xx][yy] && grid[xx][yy]=='1')
      {
       vis[xx][yy]=1;
       dfs(grid,m,n,xx,yy);
      }
     }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
     int m=grid.size();
     if(m==0)
         return 0;
     int n=grid[0].size();
     memset(vis,0,sizeof(vis));
     int cnt=0;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(!vis[i][j] && grid[i][j]=='1')
       {
        cnt++;
        dfs(grid,m,n,i,j);
       }
      }
     }
     return cnt;
    }
};

// 994. Rotting Oranges

int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
     int m=grid.size();
     if(m==0)
         return 0;
     int n=grid[0].size();
     queue<pair<int,int>>q;
     bool ff=0,gg=0;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(grid[i][j]==2)
          ff=1,q.push(make_pair(i,j));
       if(grid[i][j]==1)
           gg=1;
      }
     }
     if(!gg)
         return 0;
     if(!ff)
         return -1;
     int ans=0;
     while(!q.empty())
     {
      int zz=q.size();
      for(int i=0;i<zz;i++)
      {
       pair temp=q.front();
       q.pop();
       int x=temp.first,y=temp.second;
       for(int k=0;k<4;k++)
       {
        int xx=x+dir[k][0];
        int yy=y+dir[k][1];
        if(xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]==1)
        {
         grid[xx][yy]=2;
         q.push(make_pair(xx,yy));
        }
       }
      }
      ans++;
     }
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
        if(grid[i][j]==1)
            return -1;
      }
     }
     return (ans-1);
         
     
    }
};


// Knight Walk

const int N=505;
bool vis[N][N];
int dir[][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};


int Solution::knight(int A, int B, int C, int D, int E, int F) 
{
 int grid[A][B];
 C--;D--;E--;F--;
 if(E<0 || E>=500 || F<0 || F>=500)
  return -1;
 if(C==E && D==F)
  return 0;
 int dist[A][B];
 memset(vis,0,sizeof(vis));
 int sx=C,sy=D,dx=E,dy=F;
 for(int i=0;i<A;i++)
 {
  for(int j=0;j<B;j++)
  {
   dist[i][j]=INT_MAX; 
   
  }
 }
 dist[sx][sy]=0;
 queue<pair<int,int>>q;
 q.push(make_pair(sx,sy));
 vis[sx][sy]=1;
 while(!q.empty())
 {
  pair temp=q.front();
  q.pop();
  int x=temp.first;
  int y=temp.second;
  for(int i=0;i<8;i++)
  {
   int xx=x+dir[i][0];
   int yy=y+dir[i][1];
   if(xx>=0 && xx<A && yy>=0 && yy<B && !vis[xx][yy])
   {
     vis[xx][yy]=1;
     dist[xx][yy]=1+dist[x][y];
     q.push(make_pair(xx,yy));
   }
  }
 }
 
 /*for(int i=0;i<A;i++)
 {
  for(int j=0;j<B;j++)
  {
    cout<<dist[i][j]<<" ";
  }
  cout<<"\n";
 }*/
 if(dist[dx][dy]!=INT_MAX)
  return dist[dx][dy];
 else
  return -1;
 
}


// shortest path from source to destination in grid

#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=1e3+7;
char ch[N][N];
bool vis[N][N];
ll m,n,sx,sy,dx,dy;

void bfs()
{
 ll dist[m][n];
 ll parent[m][n][2];
 rep(i,0,m)
 {
  rep(j,0,n)
  {
   dist[i][j]=ESP;
   parent[i][j][0]=-1;
   parent[i][j][1]=-1;
  }
 }
 queue<pair<ll,ll>>q;
 q.push({sx,sy});
 dist[sx][sy]=0;
 mem(vis,0);
 vis[sx][sy]=1;
 while(!q.empty())
 {
  ll x=q.front().ff;
  ll y=q.front().ss;
  q.pop();
  rep(i,0,4)
  {
   ll xx=x+dir[i][0];
   ll yy=y+dir[i][1];
   if(xx>=0 && xx<m && yy>=0 && yy<n &&  !vis[xx][yy] && ch[xx][yy]!='#')
   {
    vis[xx][yy]=1;
    dist[xx][yy]=1+dist[x][y];
    parent[xx][yy][0]=x;
    parent[xx][yy][1]=y;
    q.push({xx,yy});
   }
  }
 }

 if(dist[dx][dy]==ESP)
    cout<<"NO"<<"\n";
 else
 {
  cout<<"YES"<<"\n";
  cout<<dist[dx][dy]<<"\n";
  string path="";
  while(dx!=-1 && dy!=-1)
  {
   if(dy==parent[dx][dy][1])
   {
   if(parent[dx][dy][0]-dx==1)
     path+='U';
   else
     path+='D';
   }
   else if(dx==parent[dx][dy][0])
   {
   if(dy-parent[dx][dy][1]==1)
     path+='R';
   else
     path+='L';
   }
   ll pp=parent[dx][dy][0];
   ll qq=parent[dx][dy][1];
   dx=pp;
   dy=qq;
  }
  reverse(path.begin(),path.end());
  cout<<path<<"\n";
 }
}


int main()
{
 hs;
 cin>>m>>n;
 rep(i,0,m)
 {
  rep(j,0,n)
  {
   cin>>ch[i][j];
   if(ch[i][j]=='A')
     sx=i,sy=j;
   if(ch[i][j]=='B')
     dx=i,dy=j;
  }
 }
 bfs();
 return 0;

}



// Minimum Cost Path


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
typedef pair<ll,pair<ll,ll>>PI;
ll HRX=1e18;
ll INF=1e9+7;



ll dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll n;
  cin>>n;
  ll a[n][n];
  ll dist[n][n];
  bool vis[n][n];
  f(n)
  {
    r(n)
    {
     cin>>a[i][j];
     vis[i][j]=0;
     dist[i][j]=HRX;
    }
  }
  priority_queue<PI,vector<PI>,greater<PI>>pq;
  pq.push(m_p(a[0][0],m_p(0,0)));
  dist[0][0]=a[0][0];
  vis[0][0]=1;

  while(!pq.empty())
  {
   PI u=pq.top();
   pq.pop();
   ll weight=u.first;
   ll x=u.second.first;
   ll y=u.second.second;
   /*if(vis[x][y])
     continue;
   vis[x][y]=1;*/
   for(ll i=0;i<4;i++)
   {
    ll xx=x+dir[i][0];
    ll yy=y+dir[i][1];
    if(xx>=0 && yy>=0 && xx<n && yy<n && dist[xx][yy]>dist[x][y]+a[xx][yy] && !vis[xx][yy])
    {
     vis[xx][yy]=1;
     dist[xx][yy]=dist[x][y]+a[xx][yy];
     pq.push(m_p(dist[xx][yy],m_p(xx,yy)));
    }
   }
  }
  cout<<dist[n-1][n-1]<<endl;
}
 return 0;
}

