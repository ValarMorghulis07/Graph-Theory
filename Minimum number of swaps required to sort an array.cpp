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

ll doit(ll a[],ll n)
{
 vector<pair<ll,ll>>vv;
 rep(i,0,n)
  vv.pb(m_p(a[i],i));
 ll ans=0;
 sort(vv.begin(),vv.end());
 bool vis[n];
 mem(vis,0);
 for(ll i=0;i<n;i++)
 {
  if(vis[i] || vv[i].second==i)// Already at right place
    continue;
  ll j=i,cycle=0;
  while(!vis[j])// find out the number of  node in this cycle and add in ans
  {
   vis[j]=1;
   j=vv[j].ss;
   cycle++;
  }
  if(cycle>0)
    ans+=cycle-1;
 }
 return ans;
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
  ll a[n];
  rep(i,0,n)
   cin>>a[i];
  cout<<doit(a,n)<<"\n";
 }
 return 0;
}
