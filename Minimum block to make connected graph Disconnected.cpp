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

const ll N=55;
char ch[N][N];
bool vis[N][N];
ll m,n,sum;

void dfs(ll x,ll y)
{
 for(ll i=0;i<4;i++)
 {
  ll xx=x+dir[i][0];
  ll yy=y+dir[i][1];
  if(xx>=0 && xx<m && yy>=0 && yy<n && ch[xx][yy]=='#' && !vis[xx][yy])
  {
   vis[xx][yy]=1;
   sum++;
   dfs(xx,yy);
  }
 }
}

int main()
{
 hs;
 cin>>m>>n;
 ll cnt=0;
 vector<pair<ll,ll>>vv;
 rep(i,0,m)
 {
  rep(j,0,n)
  {
   cin>>ch[i][j];
   if(ch[i][j]=='#')
    vv.pb(m_p(i,j)),cnt++;
  }
 }
 if(cnt<=2)
    cout<<"-1"<<"\n";
 else
 {

  ll zz=vv.size();
  bool ff=0;
  //cout<<cnt<<"\n";
  rep(i,0,zz)
  {
   mem(vis,0);
   ll sx=vv[i].ff;
   ll sy=vv[i].ss;
   ch[sx][sy]='.';
   //cout<<ch[sx][sy]<<"\n";
   sum=0;
   dfs(vv[(i+1)%zz].ff,vv[(i+1)%zz].ss);
   //cout<<sum<<" ";
   if(sum!=cnt-1)
    ff=1;
   ch[sx][sy]='#';
   //cout<<ch[sx][sy]<<"\n";

  }
  if(ff)
     cout<<"1"<<"\n";
  else
    cout<<"2"<<"\n";


 }
 return 0;
}
