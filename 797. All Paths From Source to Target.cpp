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

/*
I think the time complexity is O(2^n).
Think about this worst case scenario:
Suppose we have n nodes, labeled 0 to n-1.
Think of it as an array: [0, 1, 2, 3, 4, 5, 6, ..., n-1]
For each pair of nodes i and j, if i < j, let there be an edge between node i and node j.
(So, there are O(n^2) edges, though this fact is not important.)
Now, we want to calculate how many paths there are from the 0th node to the (n-1)th node.
Well, notice that each path of length k corresponds to some choice of (k - 1) nodes between 0 and (n-1).
For example, here are two paths of length 2:
0->3->(n-1)
0->5->(n-1)
Here is a path of length 3:
0->1->5->(n-1)
How many paths of length k are there? The answer is (n-2 choose k-1) because we pick k - 1 nodes between 0 and (n - 1).
The total number of paths is the sum of (n-2 choose k-1) for k = 1, 2, ..., (n-1).
Using the binomial theorem, this sum is equal to 2^(n-2) which is O(2^n). --> i.e(nc1+nc2+.....+ncn-1)
*/
