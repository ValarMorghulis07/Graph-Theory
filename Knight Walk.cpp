const int N=505;
bool vis[N][N];
int dir[][2]={{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};


int Solution::knight(int A, int B, int C, int D, int E, int F) 
{
 int grid[A][B];
 C--;D--;E--;F--;
 if(E<0 || E>=500 || F<0 || F>=500)
  return -1;
 if(C==E && D==F)
  return 0;
 int dist[A][B];
 memset(vis,0,sizeof(vis));
 int sx=C,sy=D,dx=E,dy=F;
 for(int i=0;i<A;i++)
 {
  for(int j=0;j<B;j++)
  {
   dist[i][j]=INT_MAX; 
   
  }
 }
 dist[sx][sy]=0;
 queue<pair<int,int>>q;
 q.push(make_pair(sx,sy));
 vis[sx][sy]=1;
 while(!q.empty())
 {
  pair temp=q.front();
  q.pop();
  int x=temp.first;
  int y=temp.second;
  for(int i=0;i<8;i++)
  {
   int xx=x+dir[i][0];
   int yy=y+dir[i][1];
   if(xx>=0 && xx<A && yy>=0 && yy<B && !vis[xx][yy])
   {
     vis[xx][yy]=1;
     dist[xx][yy]=1+dist[x][y];
     q.push(make_pair(xx,yy));
   }
  }
 }
 
 /*for(int i=0;i<A;i++)
 {
  for(int j=0;j<B;j++)
  {
    cout<<dist[i][j]<<" ";
  }
  cout<<"\n";
 }*/
 if(dist[dx][dy]!=INT_MAX)
  return dist[dx][dy];
 else
  return -1;
 
 
    
}
