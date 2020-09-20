
class Solution {
public:
    unordered_map<string,bool>vis;
    
    bool IsGood(vector<vector<int>>&mat)
    {
     for(int i=0;i<mat.size();i++)
     {
      for(int j=0;j<mat[i].size();j++)
      {
       if(mat[i][j]==1)
           return false;
      }
     }
     return true;
    }
    
    string flatten(vector<vector<int>>&temp)
    {
     string str="";
     for(int i=0;i<temp.size();i++)
     {
      for(int j=0;j<temp[i].size();j++)
      {
       str+=temp[i][j]+'0';
      }
     }
     return str;
    }
    
    void doit(vector<vector<int>>&u,queue<vector<vector<int>>>&q)
    {
      int m=u.size();
      int n=u[0].size();
      for(int i=0;i<m;i++)
      {
       for(int j=0;j<n;j++)
       {
        auto temp=u;
        temp[i][j]=1-temp[i][j];
        if(i+1<m)temp[i+1][j]=1-temp[i+1][j];
        if(i-1>=0)temp[i-1][j]=1-temp[i-1][j];
        if(j+1<n)temp[i][j+1]=1-temp[i][j+1];
        if(j-1>=0)temp[i][j-1]=1-temp[i][j-1];
        
        string s=flatten(temp);
        if(!vis[s])
        {
         vis[s]=1;
         q.push(temp);
        }
       }
      }
    }
    
    
    int minFlips(vector<vector<int>>& mat) 
    {
     vis.clear();
     int m=mat.size();
     int n=mat[0].size();
     queue<vector<vector<int>>>q;
     q.push(mat);
     int level=0;
     while(!q.empty())
     {
      int zz=q.size();
      while(zz--)
      {
       auto u=q.front();
       q.pop();
       if(IsGood(u))
           return level;
       doit(u,q);
      }
      level++;
     }
     return -1;
    }
};

/*
Time: O(mn*2^mn)--->doubt
Space: O(2^mn).
*/
