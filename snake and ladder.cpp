// DIJKSTRA
const int N=1e2+9;
vector<pair<int,int>>adj[N];
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)

int dijkstra(int src,int dest)
{
 priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
 int dist[N];
 for(int i=0;i<N;i++)
  dist[i]=INT_MAX;
 dist[src]=0;
 pq.push(m_p(0,src));
 while(!pq.empty())
 {
  int u=pq.top().second;
  pq.pop();
  for(auto xx:adj[u])
  {
    int v=xx.first;
    int w=xx.second;
    if(dist[v]>dist[u]+w)
    {
     dist[v]=dist[u]+w;
     pq.push(m_p(dist[v],v));
    }
  }
 }
 if(dist[dest]!=INT_MAX)
  return dist[dest];
 else
  return -1;
}
int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B)
{
 for(int i=0;i<N;i++)
  adj[i].clear();
 int m=A.size();
 int n=B.size();
 vector<int>vv;
 for(int i=0;i<m;i++)
 {
   adj[A[i][0]].pb(m_p(A[i][1],0));
   vv.pb(A[i][0]);
 }

 for(int i=0;i<n;i++)
 {
    adj[B[i][0]].pb(m_p(B[i][1],0));
    vv.pb(B[i][0]);
 }
 sort(vv.begin(),vv.end());
 for(int i=1;i<=100;i++)
 {
  for(int j=i+1;j<=i+6;j++)
  {
    if(!binary_search(vv.begin(),vv.end(),i))
     adj[i].pb(m_p(j,1));
  }
 }
 return dijkstra(1,100);
}

// BFS

int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) 
{
    int i, j, pos, n=10;
    unordered_map<int, int> snake, ladder;
    int ans=INT_MAX;
    for(i=0;i<A.size();i++)
        ladder[A[i][0]]=A[i][1];
    for(i=0;i<B.size();i++)
        snake[B[i][0]]=B[i][1];
    queue<pair<int, int>> q;
    q.push({1,0});
    vector<int> vis(n*n+1,0);
    while(!q.empty())
    {
        int newPos, pos = q.front().first, dist = q.front().second;
        q.pop();
        if(vis[pos]==1)
            continue;
        vis[pos]=1;
        //cout<<pos<<" "<<dist<<" ";
        if(pos==n*n)
            if(dist<ans)
                ans=dist;
        for(i=1;i<7;i++)
        {
            newPos = pos + i;
            if(newPos>n*n)
                continue;
            //cout<<newPos<<" ";
            if(snake.find(newPos)!=snake.end())
                newPos = snake[newPos];
            if(ladder.find(newPos)!=ladder.end())
                newPos = ladder[newPos];
            if(vis[newPos]==0)
                q.push({newPos, dist+1});
        }
    }
    if(ans==INT_MAX)
        return -1;
    return ans;
}
