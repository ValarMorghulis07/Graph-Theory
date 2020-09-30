// 834. Sum of Distances in Tree

/*
Explanation:-

Let's solve it with node 0 as root.


Initial an array subtree, subtree[i] counts all nodes in the subtree i.
Initial an array of res, res[i] counts sum of distance in subtree i.

Post order dfs traversal, update count and res:
subtree[root] = sum(subtree[i]) + 1
dist[root] = sum(dist[i]) + sum(subtree[i])

Pre order dfs traversal, update res:
When we move our root from parent to its child i, subtree[i] points get 1 closer to root, n - subtree[i] nodes get 1 futhur to root.
dist[i] = dist[root] - subtree[i] + N - subtree[i]

return dist, done.

Time Complexity: O(N), where NN is the number of nodes in the graph.

Space Complexity: O(N).
*/

const int N=1e4+7;
vector<int>adj[N];
    

class Solution {
public:
    vector<int>subtree,dist;
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
    {
     subtree.assign(N,1);
     dist.assign(N,0);
     for(int i=0;i<edges.size();i++)
     {
      adj[edges[i][0]].push_back(edges[i][1]);
      adj[edges[i][1]].push_back(edges[i][0]);
     }
     dfs(0,-1);
     dfs1(0,-1);
     for(int i=0;i<N;i++)
         adj[i].clear();
     return dist;
     
    }
    
     void dfs(int u,int par)
    {
     for(auto xx:adj[u])
     {
      if(xx==par)
          continue;
      dfs(xx,u);
      subtree[u]+=subtree[xx]; // cnt subtrees in node u
      dist[u]+=dist[xx]+subtree[xx]; // add sum of distances from node node u to all downward nodes
     }
    }
    
    void dfs1(int u,int par)
    {
     for(auto xx:adj[u])
     {
      if(xx==par)
          continue;
      dist[xx]=dist[u]-subtree[xx]+(subtree.size()-subtree[xx]);
      dfs1(xx,u);
     }
    }
};
