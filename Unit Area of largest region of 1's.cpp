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
