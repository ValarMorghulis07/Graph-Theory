class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph)
    {
     int n=graph.size();
     if(n==0)
         return 0;
     int total=(1<<n)-1; //for n=12 kAns = 111111111111 (all 1s means  - visited all nodes, while e.g. 111111111101 means didn't visit node 1)
     queue<pair<int,int>>q; //pair<node: bitmask> , // every time we visit some node Y on a path from node X we update  bitmask (state) of node X to set node's Y bit
     vector<vector<int>>vis(n,vector<int>(1<<n)); // 1 << n = 2^n, so we create matrix [n][2^n] where row index corresponds to node in the original graph, and column index is a bitmask(state) for particular node
     for(int i=0;i<n;i++)
         q.push({i,1<<i}); //the bitmask for each node is initialized with only its own bit set to 1 (i.e. nothing visited yet))

     int steps=0;
     while(!q.empty())
     {
      int zz=q.size();
      for(int i=0;i<zz;i++)
      {
       pair<int,int>temp=q.front(); //pair <node:bitmask>
       q.pop();
       int node=temp.first;
       int state=temp.second;
       if(state==total)
           return steps; //found a full set of 1s meaning we visited all graph nodes from the current node
       if(vis[node][state])
           continue;
       vis[node][state]=1;//for each neighbour of current node set neighbour's bit in current node's bitmask
       for(auto xx:graph[node])
           q.push({xx,state | (1<<xx)});//"state | (1 << next)" means set bit <next> in <state> bitmask
      }
      steps++;
     }
     return -1;
     
     
    }
};
