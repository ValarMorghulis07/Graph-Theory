class Solution {
public:
    /*
    Time Complexity: O(M^2*N)
    where M is the length of each word and N is the total number of words in the input word       list.
    Space Complexity: O(M^2*N)
    */
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
     unordered_set<string>ss;
     for(int i=0;i<wordList.size();i++)
         ss.insert(wordList[i]);
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
       ss.erase(word);
       for(int j=0;j<word.length();j++)
       {
         char ch=word[j];
         for(int k=0;k<26;k++)
         {
          word[j]='a'+k;
          if(ss.find(word)!=ss.end())
            q.push(word);
         }
         word[j]=ch;
       }
      }
      level++;
     }
     return 0;
    }
};
