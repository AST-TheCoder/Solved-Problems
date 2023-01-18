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

ll mod=1000000007;

ll bigmod(ll n,ll p){
    if(!p) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll ans=(n*(n+1))%mod;
        ans=(ans*(2*n+1))%mod;
        ans=(ans*bigmod(6,mod-2))%mod;
        //cout<<ans<<endl;
        ans=(2*ans)%mod;

        ll s=(n*(n+1))%mod;
        s=(s*bigmod(2,mod-2))%mod;
        ans=(ans-s+mod)%mod;
        //cout<<ans<<endl;
        ans=(ans*2022)%mod;

        cout<<ans<<endl;

    }

    return 0;
}