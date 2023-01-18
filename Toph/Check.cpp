#include<bits/stdc++.h>
using namespace std;

#define LL long long
#define ll long long
#define VI vector<LL>
const int M = 786433;
/*
7340033, 5, 4404020, 1<<20
13631489, 11799463,6244495, 1<<20
23068673, 177147,17187657, 1<<21
463470593, 428228038, 182429, 1<<21
415236097, 73362476, 247718523, 1<<22
918552577, 86995699, 324602258, 1<<22
998244353, 15311432, 469870224, 1<<23
167772161, 243, 114609789, 1<<25
469762049, 2187, 410692747, 1<<26
*/

LL power(LL a, LL p, LL mod) {
    if (p==0)   return 1;
    LL ans = power(a, p/2, mod);
    ans = (ans * ans)%mod;
    if (p%2)    ans = (ans * a)%mod;
    return ans;
}

struct NTT {
    int N;
    vector<int> perm;
    int mod, root, inv, pw;
    NTT(int mod, int root, int inv, int pw) :
        mod(mod), root(root), inv(inv), pw(pw) {}
    void precalculate() {
        perm.resize(N);
        perm[0] = 0;
        for (int k=1; k<N; k<<=1) {
            for (int i=0; i<k; i++) {
                perm[i] <<= 1;
                perm[i+k] = 1 + perm[i];
            }
        }
    }
    void fft(VI &v, bool invert = false) {
        if (v.size() != perm.size()) {
            N = v.size();
            assert(N && (N&(N-1)) == 0);
            precalculate();
        }
 
        for (int i=0; i<N; i++)
            if (i < perm[i])
                swap(v[i], v[perm[i]]);
 
        for (int len = 2; len <= N; len <<= 1) {
            LL factor = invert ? inv : root;
            for (int i = len; i < pw; i <<= 1)
                factor = (factor * factor) % mod;
 
            for (int i=0; i<N; i+=len) {
                LL w = 1;
                for (int j=0; j<len/2; j++) {
                    LL x = v[i+j], y = (w * v[i+j+len/2])%mod;
                    v[i+j] = (x+y)%mod;
                    v[i+j+len/2] = (x-y+mod)%mod;
                    w = (w * factor)%mod;
                }
            }
        }
        if (invert) {
            LL n1 = power(N, mod-2, mod);
            for (LL &x : v) x=(x*n1)%mod;
        }
    }
 
    VI multiply(VI a, VI b) {
        while (a.back() == 0 && a.size())   a.pop_back();
        while (b.back() == 0 && b.size())   b.pop_back();
        int n = 1;
        while (n < a.size()+ b.size())  n<<=1;
        a.resize(n);
        b.resize(n);
        fft(a);
        fft(b);
        for (int i=0; i<n; i++) a[i] = (a[i] * b[i])%mod;
        fft(a, true);
        return a;
    }
    VI bigMod(VI &base, int p) {
        if(p==0)return {1};
        VI ans = bigMod(base, p/2);
        ans = multiply(ans, ans);
        if (p%2)ans = multiply(ans, base);
        return ans;
    }
};

/** Find primitive root of p assuming p is prime.
if not, we must add calculation of phi(p).
Complexity : O(Ans * log (phi(n)) * log n + sqrt(p)) (if exists)
             O(p * log (phi(n)) * log n + sqrt(p))   (if does not exist)
Returns -1 if not found.
*/
ll primitive_root(ll p){
    if (p == 2) return 1;
    vector<ll> factor;
    ll phi = p-1,  n = phi;

    for (ll i=2; i*i<=n; ++i)
        if (n%i == 0) {
            factor.push_back (i);
            while (n%i==0)  n/=i;
        }

    if (n>1)  factor.push_back(n);

    for (ll res=2; res<=p; ++res) {
        bool ok = true;
        for (ll i=0; i<factor.size() && ok; ++i)
            ok &= power(res, phi/factor[i], p) != 1;
        if (ok)  return res;
    }
    return -1;
}
/**
  Generates necessary info for NTT (for offline usage :3).
  Returns maximum k such that 2^k % mod = 1,
  NTT can only be applied for arrays not larger than this size.
  mod MUST BE PRIME!!!!!
  We use the fact that if primes have the form p=c*2^k+1,
  there always exists the 2^k-th root of unity.
  It can be shown that g^c is such a 2^k-th root
  of unity, where g is a primitive root of p.
*/
ll nttdata(ll mod, ll &root, ll &inv, ll &pw) {
    ll c = 0, n = mod-1;
    while (n%2 == 0) c++, n/=2;
    pw = (mod-1)/n;
    ll g = primitive_root(mod);
    if(g == -1) return -1; // No primitive root exists
    root = power(g, n, mod);
    inv = power(root, mod-2, mod);
    return c;
}
NTT ntt(998244353, 15311432, 469870224, 1<<23);
VI res,poly[100005];

VI Divide_Con(int be,int en){
    if(be==en)return poly[be];
    int mid=(be+en)/2;
    return ntt.multiply(Divide_Con(be,mid),Divide_Con(mid+1,en));
}



int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    
    ll root,inv,pw;
    nttdata(M,root,inv,pw);
    ntt=NTT(M,root,inv,pw);

    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        vector<pair<int,int>>v;
        int hi=0;
        for(int j=1;j<=x;j++){
            int val,c;
            scanf("%d%d",&val,&c);
            v.push_back({val,c});
            hi=max(hi,val);
        }
        for(int j=0;j<=hi;j++)poly[i].push_back(0);
        for(auto[val,c]:v)poly[i][val]=c;

       // cout<<res.size()<<endl;
        
    }

    res=Divide_Con(1,n);

    int sz=res.size();
    for(int i=1;i<sz;i++)if(res[i])printf("%d %lld\n",i,res[i]);


    return 0;
}