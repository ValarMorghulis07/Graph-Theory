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
