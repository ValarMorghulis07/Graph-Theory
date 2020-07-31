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


const ll N=26;
vector<ll>adj[N];
bool vis[N];
unordered_set<char>ss;
stack<ll>stk;

void dfs(ll u)
{
 vis[u]=1;
 for(auto xx:adj[u])
 {
  if(!vis[xx])
    dfs(xx);
 }
 stk.push(u);
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
  string dict[n];
  rep(i,0,n)
   cin>>dict[i];
  for(ll i=0;i<n-1;i++)
  {
   string word1=dict[i],word2=dict[i+1];
   for(ll j=0;j<min(word1.length(),word2.length());j++)
   {
    if(word1[j]!=word2[j])
    {
     adj[word1[j]-'a'].pb(word2[j]-'a');
     ss.insert(word1[j]-'a');
     ss.insert(word2[j]-'a');
     break;
    }
   }
  }
  mem(vis,0);
  for(ll i=0;i<N;i++)
  {
   if(!vis[i] && ss.find(i)!=ss.end())
     dfs(i);
  }
  string ans="";
  while(!stk.empty())
  {
   ans+=(char)(stk.top()+'a');
   stk.pop();
  }
  cout<<ans<<"\n";
  rep(i,0,N)
   adj[i].clear();
  ss.clear();

 }
 return 0;
}
