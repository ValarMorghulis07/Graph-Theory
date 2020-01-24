#include <bits/stdc++.h>
#define mem(dp,a) memset(dp,a,sizeof(dp))
#define pb(x) push_back(x)
#define m_p(x,y) make_pair(x,y)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repush_back(i,a,b) for(ll i=a;i>=b;i--)
#define f(n) for(ll i=0;i<n;i++)
#define r(n) for(ll j=0;j<n;j++)
#define F first
#define S second
#define pi 3.14159265359
#define hs ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long int ll;
ll HRX=1e18;
ll INF=1e9+7;

const ll N=1007;
ll a[N][N];
bool vis[N][N];
ll m,n;
vector<string>vec;
string s="";

bool IsValid(ll xx,ll yy)
{
 if(xx>=0 && yy>=0 && xx<m && yy<n && a[xx][yy]==1 && !vis[xx][yy])
    return true;
 return false;
}

void path(ll x,ll y)
{
 vis[x][y]=1;
 if(x==m-1 && y==n-1)
 {
  vec.pb(s);

 }
 if(IsValid(x+1,y))
 {
  s+="D";
  path(x+1,y);
  s.pop_back();
  //vis[x+1][y]=0;
 }
 if(IsValid(x,y-1))
 {
  s+="L";
  path(x,y-1);
  s.pop_back();
  //vis[x][y-1]=0;
 }
 if(IsValid(x,y+1))
 {
  s+="R";
  path(x,y+1);
  s.pop_back();
 // vis[x][y+1]=0;
 }
 if(IsValid(x-1,y))
 {
  s+="U";
  path(x-1,y);
  s.pop_back();
  //vis[x-1][y]=0;
 }
 vis[x][y]=0;

}


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  vec.clear();
  s.clear();
  cin>>m>>n;
  f(m)
  {
   r(n)
   {
    cin>>a[i][j];
    vis[i][j]=0;
   }
  }
  path(0,0);
  sort(vec.begin(),vec.end());

  f(vec.size())
   cout<<vec[i]<<" ";
  cout<<"\n";
 }
 return 0;

}
