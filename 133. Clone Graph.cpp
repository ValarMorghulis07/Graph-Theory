class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
      if(!node)
          return NULL;
      unordered_map<Node*,Node*>mp;// To clone a graph, you need to have a copy of each node and you need to avoid copying the same node for multiple times. So you still need a mapping from an original node to its copy.
      Node* copy=new Node(node->val);//  //We create a new node with the nodes value
      mp[node]=copy; // //We store it in the map so it will help get get access to tha element in o(1) time
      queue<Node*>q;
      q.push(node);
      while(!q.empty())
      {
       Node* cur=q.front();
       q.pop();
       for(Node* xx:cur->neighbors) // //We explore all of its neighbors to make copies of edges and its adjacent nodes
       {
        if(!mp.count(xx)) //This is to make sure we dont visit the node multiple times
        {
         mp[xx]=new Node(xx->val); ////We create the new nodes
         q.push(xx);
        }
        mp[cur]->neighbors.push_back(mp[xx]); // //This the creation of edges
        
       }
      }
      return copy;
      
      
    }
};
