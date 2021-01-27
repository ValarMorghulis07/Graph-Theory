// eulerian path
  
//Problem Link:- https://cses.fi/problemset/task/1693/

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
const ll N=1e5+7;
vector<ll>adj[N];
ll in[N],out[N];
ll n,e,st=-1,ed=-1;
stack<ll>stk;

bool IsEuler()
{
 ll cnt1=0,cnt2=0;
 rep(i,1,n+1)
 {
  if(in[i]!=out[i])
  {
    if(in[i]-out[i]==1) // ending node in euler path
        cnt1++,ed=i;
    else if(out[i]-in[i]==1) // // starting node in euler path
        cnt2++,st=i;
    else
        return 0;
  }
 }
 if(cnt1<=1 && cnt1==cnt2)
    return 1;
 return 0;
}

void dfs(ll u)
{
 while(!adj[u].empty())
 {
  ll v=adj[u].back();
  adj[u].pop_back();
  dfs(v);
 }
 stk.push(u);
}

int main()
{
 hs;
 cin>>n>>e;
 rep(i,0,e)
 {
  ll x,y;
  cin>>x>>y;
  adj[x].pb(y);
  in[y]++;
  out[x]++;
 }
 if(IsEuler())
 {
  if(st==-1)// if all vertex have equal in and outdegree then any node can be starting point (b'coz its eulerian circuit and hence eulerian cycle)
    st=1;
  dfs(st);
  if(stk.size()!=e+1 || st!=1 || ed!=n) //this is used to check all edges are removed
    cout<<"IMPOSSIBLE"; // here( (st!=1 || ed!=n) these two are checked a/c to question demand otherwise it's not necesaary in eulerian path/circuit)
  else
  {
  while(!stk.empty())
  {
   cout<<stk.top()<<" ";
   stk.pop();
  }
  }
 }
 else
    cout<<"IMPOSSIBLE";
 return 0;
}

// Time complexity : O(E)
