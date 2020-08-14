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
ll dir[][2]={{0,1},{0,-1},{1,0},{-1,0}};
/*
 freopen("in.txt","r",stdin);
 freopen("out.txt","w",stdout);
*/

const ll N=1e3+7;
ll dist[N][N];

void floyddWarshall(ll n)
{
 for(ll k=0;k<n;k++)
 {
  for(ll i=0;i<n;i++)
  {
   for(ll j=0;j<n;j++)
   {
    if(dist[i][j]>dist[i][k]+dist[k][j])
        dist[i][j]=dist[i][k]+dist[k][j];
   }
  }
 }
}

int main()
{
 hs;
 ll t;
 cin>>t;
 while(t--)
 {
  ll n;
  cin>>n;
  ll dist[n][n];
  rep(i,0,n)
  {
   rep(j,0,n)
   {
    cin>>dist[i][j];
   }
  }
  floyddWarshall(n);
  rep(i,0,n)
  {
   rep(j,0,n)
   {
    cout<<dist[i][j]<<" ";
   }
   cout<<"\n";
  }

 }
 return 0;
}
