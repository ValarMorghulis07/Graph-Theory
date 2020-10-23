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
