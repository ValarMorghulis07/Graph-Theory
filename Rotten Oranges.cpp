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


int main()
{
 hs;
 ll t;
 cin>>t;
 f(t)
 {
  ll m,n;
  cin>>m>>n;
  ll a[m][n];
  queue<pair<ll,ll>>q;
  f(m)
  {
   r(n)
   {
    cin>>a[i][j];
    if(a[i][j]==2)
      q.push(m_p(i,j));
   }
  }
  ll time=0;
  while(!q.empty())
  {
   ll zz=q.size();
   for(ll i=0;i<zz;i++)
   {
    ll x=q.front().first;
    ll y=q.front().second;
    if(y-1>=0 && a[x][y-1]==1)
    {
     a[x][y-1]=2;
     q.push(m_p(x,y-1));
    }
    if(y+1<n && a[x][y+1]==1)
    {
     a[x][y+1]=2;
     q.push(m_p(x,y+1));
    }
    if(x-1>=0 && a[x-1][y]==1)
    {
     a[x-1][y]=2;
     q.push(m_p(x-1,y));
    }
    if(x+1<m && a[x+1][y]==1)
    {
     a[x+1][y]=2;
     q.push(m_p(x+1,y));
    }
   }
   time++;
  }
  for(ll i=0;i<m;i++)
  {
    for(ll j=0;j<n;j++)
    {
     if(a[i][j]==1)
     {
      time=0;
      break;
     }
    }
    if(time==0)
     break;
  }
  cout<<time-1<<endl;

 }
 return 0;
}
