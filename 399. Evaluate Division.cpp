class Solution {
public:
    unordered_map<string,vector<pair<string,double>>>mp;
    double bfs(string src,string dest)
    {
     if(mp.find(src)==mp.end() || mp.find(dest)==mp.end())
         return -1.0;
     unordered_map<string,bool>vis;
     queue<pair<string,double>>q;
     q.push({src,1.0});
     vis[src]=1;
     while(!q.empty())
     {
      string u=q.front().first;
      double val=q.front().second;
      if(u==dest)
          return val;
      q.pop();
      for(auto xx:mp[u])
      {
       if(!vis[xx.first])
       {
        vis[xx.first]=1;
        q.push({xx.first,val*xx.second});
       }
      }
     }
     return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
     mp.clear();
     vector<double>ans;
     for(int i=0;i<equations.size();i++)
     {
      mp[equations[i][0]].push_back({equations[i][1],values[i]});
      mp[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
     }
     for(int i=0;i<queries.size();i++)
       ans.push_back(bfs(queries[i][0],queries[i][1]));
     return ans;
     
     
    }
};
