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

ll bigmod(ll n,ll p,ll mod){
    if(!p) return 1;
    if(p%2) return (n*bigmod(n,p-1,mod))%mod;
    ll x=bigmod(n,p/2,mod);
    return (x*x)%mod;
}

int main()
{

    ll mod=1000000007;
    cout<<(13LL*bigmod(9,mod-2,mod))%mod<<endl;

    ll t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;

        ll s=0;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;

            s+=x%n;
        }
        s=bigmod(s,k,mod);
        n=bigmod(n,k,mod);

        ll ans=(s*bigmod(n,mod-2,mod))%mod;
        cout<<ans<<endl;
    }


    return 0;
}