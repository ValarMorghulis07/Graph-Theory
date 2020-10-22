// Flood fill Algorithm

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


// Sum of dependencies in a graph

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

const ll N=1007;
vector<ll>adj[N];
ll n,e;

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
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
 }
 cout<<e<<endl;
 }
 return 0;
}

// Given a directed and connected graph with n nodes. If there is an edge from u to v then u depends on v.


// Transitive closure of a Graph

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
vector<ll>adj[N];
bool vis[N];
ll a[N][N];
vector<ll>ans;
ll n;

void bfs(ll src)
{
 mem(vis,0);
 ll dist[n];
 f(n)
  dist[i]=HRX;
 dist[src]=0;
 queue<ll>q;
 if(!vis[src])
    vis[src]=1;
 q.push(src);
 while(!q.empty())
 {
  ll u=q.front();
  q.pop();
  f(adj[u].size())
  {
    ll v=adj[u][i];
    if(!vis[v])
    {
     vis[v]=1;
     dist[v]=dist[u]+1;
     q.push(v);
    }
  }
 }
 f(n)
 {
  if(dist[i]!=HRX)
    ans.pb(1);
  else
    ans.pb(0);
 }
}
int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  cin>>n;
  f(n)
  {
    r(n)
    {
     cin>>a[i][j];
     if(a[i][j]==1)
        adj[i].pb(j);
    }
  }
  f(n)
   bfs(i);
  f(ans.size())
   cout<<ans[i]<<" ";
  cout<<"\n";
  f(N)
   adj[i].clear();
  ans.clear();

 }
 return 0;
}

/*
Transitive Closure it the reachability matrix to reach from vertex u to vertex v of a graph. One graph is given, we have to find a vertex v 
which is reachable from another vertex u, for all vertex pairs (u, v). 
*/

// number of island

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

const ll N=51;
ll a[N][N];
bool vis[N][N];
ll n,m;
ll dir[][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

void dfs(ll c,ll d)
{
   if(!vis[c][d])
   {
   vis[c][d]=1;
   for(ll i=0;i<8;i++)
   {
     ll xx=c+dir[i][0];
     ll yy=d+dir[i][1];
     if(xx>=0 && yy>=0 && xx<n && yy<m)
     {
       if(a[xx][yy]-a[c][d]==0)
          dfs(xx,yy);
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
  ll cnt=0;
  cin>>n>>m;
  f(n)
  {
    r(m)
    {
      cin>>a[i][j];
      vis[i][j]=0;
    }
  }

  f(n)
  {
    r(m)
    {
      if(a[i][j]==1)
      {
        if(!vis[i][j])
        {
           dfs(i,j);
             cnt++;
        }
      }
     }
  }
  cout<<cnt<<endl;
  }
  return 0;
}

// Unit Area of largest region of 1's

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
     return max(maxx,cnt); // [[1]] for this ,maxx=0 and cnt=1
     
    }
};

// Rotten Oranges

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
      ans++; // after complete rotting it is counted one more time
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


// Replace O's with X's

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


// Mother vertex

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

const int N=2*10001;
 bool vis[N];
 int mother;
 void dfs(int u,vector<int> adj[])
 {
   vis[u]=1;
   for(int i=0;i<adj[u].size();i++)
   {
      int v=adj[u][i];
      if(!vis[v])
         dfs(v,adj);
   }
 }

 void dfs1(int u,vector<int> adj[])
 {
   vis[u]=1;
   for(int i=0;i<adj[u].size();i++)
   {
      int v=adj[u][i];
      if(!vis[v])
         dfs1(v,adj);
   }
 }
int findMother(int V, vector<int> adj[])
{
  memset(vis,0,sizeof(vis));
  for(int i=0;i<V;i++)
  {
     if(!vis[i])
     {
        dfs(i,adj);
        mother=i;
     }
  }
  memset(vis,0,sizeof(vis));
  dfs1(mother,adj);
  int ff=0;
  for(int i=0;i<V;i++)
  {
    if(vis[i]!=1)
    {
      ff=1;
      break;
    }
  }
  if(ff==0)
    return mother;
  else if(ff==1)
    return -1;


}

// There can be more than one mother vertices in a graph. We need to output anyone of them
// If there exist mother vertex (or vertices), then one of the mother vertices is the last finished vertex in DFS.


// PT07Z - Longest path in a tree

#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi 3.141592653589793238462
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll INF=1e9+7;

const ll N=1e4+7;
vector<ll>adj[N];
ll node,n,dist;

void dfs(ll u,ll par,ll lev)
{
 if(lev>=dist)
 {
  dist=lev;
  node=u;
 }
 for(auto x:adj[u])
 {
  if(x!=par)
    dfs(x,u,lev+1);
 }
}


int main()
{
 hs;
 cin>>n;
 f(n-1)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  adj[y].pb(x);
 }
 dist=-1;
 dfs(1,-1,0);
 dist=-1;
 dfs(node,-1,0);
 cout<<dist<<"\n";
 return 0;

}

// snake and ladder

// DIJKSTRA
const int N=1e2+9;
vector<pair<int,int>>adj[N];
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)

int dijkstra(int src,int dest)
{
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 int dist[N];
 for(int i=0;i<N;i++)
  dist[i]=INT_MAX;
 dist[src]=0;
 pq.push(m_p(0,src));
 while(!pq.empty())
 {
  int u=pq.top().second;
  pq.pop();
  for(auto xx:adj[u])
  {
    int v=xx.first;
    int w=xx.second;
    if(dist[v]>dist[u]+w)
    {
     dist[v]=dist[u]+w;
     pq.push(m_p(dist[v],v));
    }
  }
 }
 if(dist[dest]!=INT_MAX)
  return dist[dest];
 else
  return -1;
}
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
 for(int i=0;i<N;i++)
  adj[i].clear();
 int m=A.size();
 int n=B.size();
 vector<int>vv;
 for(int i=0;i<m;i++)
 {
   adj[A[i][0]].pb(m_p(A[i][1],0));
   vv.pb(A[i][0]);
 }

 for(int i=0;i<n;i++)
 {
    adj[B[i][0]].pb(m_p(B[i][1],0));
    vv.pb(B[i][0]);
 }
 sort(vv.begin(),vv.end());
 for(int i=1;i<=100;i++)
 {
  for(int j=i+1;j<=i+6;j++)
  {
    if(!binary_search(vv.begin(),vv.end(),i))
     adj[i].pb(m_p(j,1));
  }
 }
 return dijkstra(1,100);
}

// BFS

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) 
{
    int i, j, pos, n=10;
    unordered_map<int, int> snake, ladder;
    int ans=INT_MAX;
    for(i=0;i<A.size();i++)
        ladder[A[i][0]]=A[i][1];
    for(i=0;i<B.size();i++)
        snake[B[i][0]]=B[i][1];
    queue<pair<int, int>> q;
    q.push({1,0});
    vector<int> vis(n*n+1,0);
    while(!q.empty())
    {
        int newPos, pos = q.front().first, dist = q.front().second;
        q.pop();
        if(vis[pos]==1)
            continue;
        vis[pos]=1;
        //cout<<pos<<" "<<dist<<" ";
        if(pos==n*n)
            if(dist<ans)
                ans=dist;
        for(i=1;i<7;i++)
        {
            newPos = pos + i;
            if(newPos>n*n)
                continue;
            //cout<<newPos<<" ";
            if(snake.find(newPos)!=snake.end())
                newPos = snake[newPos];
            if(ladder.find(newPos)!=ladder.end())
                newPos = ladder[newPos];
            if(vis[newPos]==0)
                q.push({newPos, dist+1});
        }
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}

