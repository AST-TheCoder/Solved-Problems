#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

ll mod,n,fact[3000007],inv[1000007];

ll bigmod(ll x,ll p){
    if(!p) return 1;
    if(p%2) return (x*bigmod(x,p-1))%mod;
    ll v=bigmod(x,p/2);
    return (v*v)%mod;
}

int main()
{

    scanf("%lli %lli",&n,&mod);

    fact[0]=1;
    inv[0]=1;
    for(ll i=1;i<=3*n;i++){
        fact[i]=(i*fact[i-1])%mod;
        if(i<=n) inv[i]=bigmod(fact[i],mod-2);
    }
    
    ll op1=(2*fact[2*n])%mod;
    op1=(op1-fact[n]-1+2*mod)%mod;

    
    ll op2=(fact[2*n]*inv[n])%mod;
    op2=(2*op2*fact[2*n])%mod;

    for(ll i=0;i<=n;i++){
        ll temp=(bigmod(fact[n],4)*fact[2*n-i])%mod;
        temp=(temp*inv[n-i])%mod;
        temp=(temp*inv[n-i])%mod;
        temp=(temp*inv[n-i])%mod;
        temp=(temp*inv[i])%mod;
        temp=(temp*inv[i])%mod;

        op2=(op2-temp+mod)%mod;
    }
    
    op2=(op2-op1-1+mod)%mod;

    ll op3=(fact[3*n]-op1-op2-1+3*mod)%mod;

    //cout<<op1<<" "<<op2<<" "<<op3<<endl;
    ll ans=(op1+2*op2+3*op3)%mod;
    printf("%lli\n",ans);

    return 0;
}