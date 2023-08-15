#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;

#define fi first
#define se second
 
#define pb push_back
#define sz(x) ((int) (x).size())
#define rep(i,n) for (int i=1;i <=int(n);i++)
#define repi(I, A, B) for (int I = (A); I <= (B); ++I)
#define rrepp(I, B, A) for (int I = (B); I >= (A); --I)
#define ffor(i,n) for (int i=0;i <int(n);i++)
#define all(x) x.begin(),x.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // use rng() for random
const ll mod = 1e9 + 7;
ll fac[5000001];
ll add(ll& a, ll b) {a += b;  if (a >= mod)  a -= mod;  return a; }
ll sub(ll& a, ll b) {a -= b;   if (a < 0)    a += mod;  return a; }
ll mul(ll& a, ll b) {  ll c = ll(a) * b;if (c >= mod)  c %= mod;  a = c;   return a;}

ll bpow(ll a, ll n) {
     ll ans = 1;  a%=mod;
     while (n) {
          if (n & 1)  mul(ans, a);
          n >>= 1;    mul(a, a);
     }
     return ans;
}
ll inv(ll a){  return bpow(a,mod-2);}
ll choose(ll n , ll k){
     if ( k < 0 || k > n ) return 0;
     ll res = fac[n] ;
     res = res * inv(fac[k]); res %= mod;
     res = res * inv(fac[n-k]);res %= mod;
     return res;
}

   
template<typename T>
struct lazysegtree {
     vector<T> tree;
     vector<ll> laz;
     vector<int> mark;
     int size;
     //
     void init(int n)
       {
           size = n;
           tree = vector<T>(8 * n +5,0);
           laz = vector<ll>(8 * n +5,1);
           mark = vector<int>(8 * n +5,0);
       }
     //
     void up(int i ){
          tree[i] = (tree[i*2] + tree[i*2+1]) % mod;
     }
     //
     T comb(T x, T y)
     {
          return  ( x + y ) % mod;
     }
     //
     void build(int i,int l, int r,ll arr[]){
        
        laz[i]=1;
          if (l==r) {
              
               tree[i] = arr[l];
               return;
          }
          int mid=(l+r)/2;
          build(i*2,l,mid,arr);
          build(i*2+1,mid+1,r,arr);
          up(i);
     }
     //
     void modify(int i,int l,int r,ll incr){
           //do sth
         laz[i] *= incr; laz[i] %= mod;
         tree[i] *= incr; tree[i] %= mod;
     }
     //
     void push(int i,int l,int r){
          if (laz[i]==1) return;
          int mid=(l+r)/2;
          ll now = laz[i];
          //left child
          modify(i*2,l,mid,now);
          // right child
          modify(i*2+1,mid+1,r,now);
          // reset
          laz[i] = 1;
          
     }
     //
     T get(int i,int l,int r,int ql, int qr){
          if (l > qr || r < ql ) return 0; //  ql   -  qr  -   l  -  r  ||   l - r  - ql - qr
          if (ql <= l && r <= qr){          // ql   -  l   -   r  - qr
               return tree[i];
          }
          push(i,l,r);
        
          int mid=(l+r)/2;
          up(i);
          return comb(get(i*2,l,mid,ql,qr),get(i*2+1,mid+1,r,ql,qr));
     }
     
     //
     void rangemul(int i,int l,int r,int ql,int qr,ll incr){
          if (l > qr || r < ql ) return;  //  ql - qr  -  l - r  ||   l - r  - ql - qr
          if (ql <= l && r <= qr){       //   ql -  l  -  r - qr
               modify(i,l,r,incr);
               return;
          }
          push(i,l,r);
          int mid= (l+r)/2;
          rangemul(i*2,l,mid,ql,qr,incr);
          rangemul(i*2+1,mid+1,r,ql,qr,incr);
          up(i);
        
     }
    void insval(int i,int l,int r,int ind,ll incr){
        
             if (l == r){       //   ql -  l  -  r - qr
                 tree[i] = incr;
                  return;
             }
             push(i,l,r);
             int mid= (l+r)/2;
        if (ind <= mid) insval(i*2,l,mid,ind,incr); else  insval(i*2+1,mid+1,r,ind,incr);
            
             up(i);
           
        }
    void mmul(int ql ,int qr,ll incr){
        if (ql > qr) return;

        rangemul(1,0,size-1,ql,qr,incr);
    }
};
ll a[500005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;
    while (t--){
    int n ; cin >> n;
    lazysegtree<ll> S;
    S.init(n);
    a[0] = 1;
    rep(i,n) a[i] = 0;
    S.build(1,0,n-1,a);
  
    ll x; cin >> x;
    for (ll i = 2 ; i <= n ; i++){
      
      //  for (int k = 0 ; k < i ; k ++ ) cout << x/i + (k < x % i) << ' '; cout << '\n';
        // event i
       // dp[i][i-1] = sum(P(j) * dp[i-1][j]); j < i-1 -> 0 -> x%i - 1 , x%i  -> i-1
        // dp[i][j] = P(i-1) * dp[i-1][j]; j < i-1
        // P(k) = X/i + (k < X mod i)  / X
        ll Pk =  ( x/i + 1 )% mod * inv(x); Pk %= mod;
        
        ll sum = 0 ;
     
        if ( x % i > 0) {sum = (S.get(1,0,n-1,0, (x % i)-1 ) * Pk ) % mod;}
        
        
        
        Pk =  ( x/i  )% mod * inv(x); Pk %= mod;
        
        sum += S.get(1,0,n-1, x%i , i-2) * Pk; sum %= mod;
        
        S.insval(1,0,n-1,i-1,sum);
        

         Pk =  ( x/i   )% mod * inv(x); Pk %= mod;
        
        S.mmul(0,i-2,Pk);
        
       
        
    }
    
 
    cout << S.get(1,0,n-1,0,n-1) << '\n';
    }
    return 0;
}