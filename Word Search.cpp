#include<bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define per(i,b,a) for (ll i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define ff first
#define ss second
#define pi acosl(-1.0l)
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fixed(n) fixed<<setprecision(n)
using namespace std;
typedef long long int ll;
typedef long double ld;
ll ESP=1e18;
ll FCB=1e9+7;
ll prime=119;
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=1e3+7;
char ch[N][N];
string word;
ll m,n;

bool dfs(ll x,ll y,ll idx)
{
 for(ll i=0;i<4;i++)
 {
  ll xx=x+dir[i][0];
  ll yy=y+dir[i][1];
  if(idx==word.length())
    return true;
  if(xx>=0 && xx<m && yy>=0 && yy<n && idx<word.length() && ch[xx][yy]==word[idx])
  {
   ch[xx][yy]='$';//  this prevents reusage of characters
   if(dfs(xx,yy,idx+1))
   {
    ch[xx][yy]=word[idx];// again changing it to its previous state if solution found
     return true;
   }
   ch[xx][yy]=word[idx];// again changing it to its previous state if solution not found


  }
 }
 return false;
}

int main()
{
 hs;
  cin>>m>>n;
  rep(i,0,m)
  {
   rep(j,0,n)
   {
    cin>>ch[i][j];
   }
  }
  ll q;
  cin>>q;
  while(q--)
  {
  cin>>word;
  bool ff=0;
  for(ll i=0;i<m;i++)
  {
   for(ll j=0;j<n;j++)
   {
    if(ch[i][j]==word[0])
    {
     ch[i][j]='$';
     if(dfs(i,j,1))
       ff=1;
     ch[i][j]=word[0];
    }
   }
  }
  if(ff)
    cout<<"Found";
  else
    cout<<"Not Found";
  cout<<"\n";
  
  }

 return 0;
}

/*

3 4
ABCE
SFCS
ADEE
6
FCSD
SEE
ABCB
ABCCED
A
ABCCFSADEESE
*/

