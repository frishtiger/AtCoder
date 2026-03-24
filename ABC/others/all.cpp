/*
#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef pair<ll,ll> pl;
typedef pair<ll,pl> ppl;
typedef pair<ll,ppl> pppl;
typedef pair<ll,pppl> pppppl;
#define pb push_back
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) begin(a),end(a)
#define rall(a) rbegin(a),rend(a)
#define sz(a) (int)(a).size()
#define F first
#define S second
#define bs(A,x) binary_search(all(A),x)
#define lb(A,x) (ll)(lower_bound(all(A),x)-A.begin())
#define ub(A,x) (ll)(upper_bound(all(A),x)-A.begin())
#define cou(A,x) (ll)(upper_bound(all(A),x)-lower_bound(all(A),x))
template<typename T>using min_priority_queue=priority_queue<T,vector<T>,greater<T>>;
template<class T>bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T&a,T b){if(b<a){a=b;return 1;}return 0;}
void Yes(bool b){cout<<(b?"Yes":"No")<<endl;}
void YES(bool b){cout<<(b?"YES":"NO")<<endl;}

using mint=modint998244353;
const ll mod=998244353;


using mint=modint1000000007;
const ll mod=1000000007;

using mint=modint;
typedef vector<mint> vm;
typedef vector<vm> vvm;
typedef vector<vvm> vvvm;
typedef vector<vvvm> vvvvm;
ostream&operator<<(ostream&os,mint a){os<<a.val();return os;}
istream&operator>>(istream&is,mint&a){int x;is>>x;a=mint(x);return is;}

template<typename T1,typename T2>ostream&operator<<(ostream&os,pair<T1,T2>p){os<<p.F<<" "<<p.S;return os;}
template<typename T1,typename T2>istream&operator>>(istream&is,pair<T1,T2>&p){is>>p.F>>p.S;return is;}
template<typename T>ostream&operator<<(ostream&os,vector<T>v){rep(i,0,sz(v))os<<v[i]<<(i+1!=sz(v)?" ":"");return os;}
template<typename T>istream&operator>>(istream&is,vector<T>&v){for(T&in:v)is>>in;return is;}
long long mfloor(long long x,long long y){
  return (x/y-((x^y)<0&&(x%y)));
}
template <typename T>
auto rle(const T&x){
  vector<pair<typename T::value_type,int>>y;
  int num=1;
  for(int i=1;i<sz(x);i++){
    if(x[i]!=x[i-1]){
      y.push_back({x[i-1],num});
      num=0;
    }
    num++;
  }
  y.push_back({x.back(),num});
  return y;
}
int C=400009;
vector<mint> fact(C+1),invfact(C+1);
mint binom(int n,int r){
  if (r>n) return 0;
  else{
    return fact[n]*invfact[r]*invfact[n-r];
  }
}
void dfs(int u,vector<vector<int>>&G,vector<bool>&ok){
  ok[u]=true;
  for(auto v:G[u]){
    if(!ok[v])dfs(v,G,ok);
  }
}
vector<long long> dijkstra(int s,vector<vector<pair<long long,long long>>>&G){
  int n=sz(G);
  long long INF=1e18;
  vector<long long>cur(n,INF);
  cur[s]=0;
  min_priority_queue<pair<long long,long long>>Q;
  Q.push({0,s});
  while(!Q.empty()){
    ll a=Q.top().first;
    ll b=Q.top().second;
    Q.pop();
    if(a>cur[b])continue;
    for(auto [v,cost]:G[b]){
      if(cur[b]+cost<cur[v]){
        cur[v]=cur[b]+cost;
        Q.push({cur[v],v});
      }
    }
  }
  return cur;
}
int main(){
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  fact[0]=1;
  invfact[0]=1;
  for(int i=1;i<=C;i++) fact[i]=fact[i-1]*i;
  invfact[C]=fact[C].inv();
  for(int i=C-1;i>=1;i--) invfact[i]=invfact[i+1]*(i+1);
  //
  int n;
  cin>>n;
  vl a(100);
  a[0]=2;
  a[1]=1;
  rep(i,2,90)a[i]=a[i-1]+a[i-2];
  cout<<a[n]<<endl;
}
*/
//TKTY1
//Lucas Number
#include <iostream>
int main() {std::cout << "Hello World!" << '\n'; return 0;}