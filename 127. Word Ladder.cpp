 // 127. Word Ladder 

/*
    Time Complexity: O(M^2*N)
    where M is the length of each word and N is the total number of words in the input word list.
    Space Complexity: O(M^2*N)
    */
   class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
     unordered_set<string>ss;
     for(int i=0;i<wordList.size();i++)
       ss.insert(wordList[i]); 
     if(ss.find(endWord)==ss.end())
         return 0;
     int level=1;
     queue<string>q;
     q.push(beginWord);
     while(!q.empty())
     {
      int n=q.size();
      for(int i=0;i<n;i++)
      {
       string word=q.front();
       q.pop();
       if(word==endWord)
           return level;
      // ss.erase(word);
       for(int j=0;j<word.length();j++)
       {
         char ch=word[j];
         for(int k=0;k<26;k++)
         {
          word[j]='a'+k;
          if(ss.find(word)!=ss.end())
            ss.erase(word),q.push(word);// Remove all words from dict if found and  push it in queue 
          
         }
         word[j]=ch;
       }
      }
      level++;
     }
     return 0;
    }
};

// 79. Word Search

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

// What is the time complexity? I think it is O(N^2 * 4^k) where k is the length of word


// 399. Evaluate Division

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


