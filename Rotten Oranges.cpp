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
