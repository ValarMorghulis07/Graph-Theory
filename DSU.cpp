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

const ll N=1e3+7;
vector<ll>adj[N];
ll id[N],sze[N];
ll n,e;

void intitialize()
{
 f(N)
 {
  id[i]=i;
  sze[i]=1;

 }
}

ll root(ll x)
{
 while(id[x]!=x)
 {
  id[x]=id[id[x]];
  x=id[x];
 }
 return x;
}

 bool find(ll A,ll B)
 {
        if( root(A)==root(B) )       //if A and B have the same root, it means that they are connected.
        return true;
        else
        return false;
 }


int main()
{
 hs;
 intitialize();
 cin>>n>>e;
 ll a[e],b[e];
 f(e)
  cin>>a[i]>>b[i];
 for(ll i=0;i<e;i++)
 {
  ll A=root(a[i]);
  ll B=root(b[i]);
  if(sze[A]<sze[B])
  {
   id[A]=id[B];
   sze[B]+=sze[A];
   sze[A]=0;
  }
  else
  {
   id[B]=id[A];
   sze[A]+=sze[B];
   sze[B]=0;
  }
  vector<ll>ans;
  for(ll i=1;i<=n;i++)
    {
     if(sze[i]!=0)
        ans.pb(sze[i]);
    }
    sort(ans.begin(),ans.end());
    f(ans.size())
     cout<<ans[i]<<" ";
    cout<<"\n";


 }
 return 0;
}
/*
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/count-friends/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/teachers-dilemma-3/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/owl-fight/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/still-maximum/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/lexicographically-minimal-string-6edc1406/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/friends-and-foes/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/monk-and-palindromes/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/killjee-and-cities-8a82b6fe/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/group-range-a6693ae2/
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/marriage-problem/
*/
