We regard

a cell in the matrix as a node,
a directed edge from node x to node y if x and y are adjacent and x's value > y's value
Topological sort is always helpful to problems in a DAG.

The longest path is actually the longest chain of nodes in the topological order.

So we use BFS to implement the topological sort, and maintain the length.


int dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
     int m=matrix.size();
     if(m==0)return 0;
     int n=matrix[0].size();
     int indegree[m][n];
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
        indegree[i][j]=0;
      }
     }
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       for(int k=0;k<4;k++)
       {
        int xx=i+dir[k][0];
        int yy=j+dir[k][1];
        if(xx>=0 && xx<m && yy>=0 && yy<n)
        {
         if(matrix[xx][yy]>matrix[i][j])
             indegree[i][j]++;
        }
       }
      }
     }
     queue<pair<int,int>>q;
     for(int i=0;i<m;i++)
     {
      for(int j=0;j<n;j++)
      {
       if(indegree[i][j]==0)
           q.push(make_pair(i,j));
      }
     }
     int ans=0;
     while(!q.empty())
     {
      int zz=q.size();
      for(int i=0;i<zz;i++)
      {
       pair temp=q.front();
       q.pop();
       int x=temp.first,y=temp.second;
       for(int j=0;j<4;j++)
       {
         int xx=x+dir[j][0];
         int yy=y+dir[j][1];
         if(xx>=0 && xx<m && yy>=0 && yy<n)
         {
          if(matrix[x][y]>matrix[xx][yy] && --indegree[xx][yy]==0)
              q.push(make_pair(xx,yy));
         }
       }
      }
      ans++;
     }
     return ans;


    }
};
