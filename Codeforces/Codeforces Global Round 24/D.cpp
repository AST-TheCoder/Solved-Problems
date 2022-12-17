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

ll n,mod,fact[5007],inv[5007];

ll bigmod(ll v,ll e){
    if(!e) return 1;
    if(e%2) return (v*bigmod(v,e-1))%mod;

    ll x=bigmod(v,e/2);
    return (x*x)%mod;
}

int main()
{

    cin>>n>>mod;
    fact[0]=1;
    for(ll i=1;i<5007;i++) fact[i]=(fact[i-1]*i)%mod;
    for(ll i=0;i<5007;i++) inv[i]=bigmod(fact[i],mod-2);

    ll ans=0;
    if(n%2==0) ans=(n*fact[n-2])%mod;

    for(ll i=2;i<=(n+1)/2;i++){
        ll temp=0;
        for(ll j=i-1;j<(n+1)/2;j++){
            ll c=1;
            if(i!=2){
                c=(c*fact[j-1])%mod;
                c=(c*inv[i-2])%mod;
                c=(c*inv[(j-1)-(i-2)])%mod;
            }
            if(n%2) c=(c*j)%mod;
            else c=(c*(j+1))%mod;
            c=(c*fact[n-i-1])%mod;

            temp=(temp+c)%mod;
        }
        temp=(temp*n)%mod;
        ans=(ans+temp)%mod;
    }

    cout<<ans<<endl;

    return 0;
}