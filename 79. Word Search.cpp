
int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};

class Solution {
public:
    bool dfs(vector<vector<char>>& board,string word,int m,int n,int x,int y,int idx)
    {
     for(int i=0;i<4;i++)
    {
    int xx=x+dir[i][0];
    int yy=y+dir[i][1];
  if(idx==word.length())
    return true;
  if(xx>=0 && xx<m && yy>=0 && yy<n && idx<word.length() && board[xx][yy]==word[idx])
  {
   board[xx][yy]='$';//  this prevents reusage of characters
   if(dfs(board,word,m,n,xx,yy,idx+1))
   {
    board[xx][yy]=word[idx];// again changing it to its previous state, if found
     return true;
   }
   board[xx][yy]=word[idx];// again changing it to its previous state, if not found


  }
 }
  return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) 
    {
     if(word.length()==0)
         return 1;
     int m=board.size();
     int n=board[0].size();
     bool ff=0;
     vector<pair<int,int>>vv;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(board[i][j]==word[0])
       {
        board[i][j]='$';
        if(dfs(board,word,m,n,i,j,1))
            ff=1;
        board[i][j]=word[0];
       }
      }
     }
    
     
     return ff==1;
    }
};
