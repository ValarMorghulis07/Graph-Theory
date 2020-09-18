// Given a directed acyclic  graph of N nodes. Find all possible paths from node 0 to node N-1, and return them in any order.


class Solution {
public:
    vector<vector<int>>ans;
    void dfs(int u,int dest,vector<int>vv,vector<vector<int>>& graph)
    {
     vv.push_back(u);
     if(u==dest)
     {
      ans.push_back(vv);
      return;
     }
     for(auto xx:graph[u])
        dfs(xx,dest,vv,graph);
     }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
     ans.clear();
     int n=graph.size();
     if(n==0)
         return ans;
     vector<int>vv;
     dfs(0,n-1,vv,graph);
     return ans;
    }
};
