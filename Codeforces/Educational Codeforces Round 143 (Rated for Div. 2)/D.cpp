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

ll mod=998244353;
ll bigmod(ll n,ll p){
    if(!p) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

int main()
{

    ll n;
    cin>>n;

    ll a[n+1];
    for(ll i=1;i<=n;i++) cin>>a[i];

    ll ans=1,x=n/3;
    for(ll i=1;i<=x/2;i++){
        ans=(ans*(x-i+1))%mod;
        ans=(ans*bigmod(i,mod-2))%mod;
    }

    for(ll i=1;i<=n;i+=3){
        vector<ll> temp;
        for(ll j=i;j<=i+2;j++) temp.pb(a[j]);
        sort(all(temp));
        if(temp[0]==temp[2]) ans=(ans*3)%mod;
        else if(temp[0]==temp[1]) ans=(ans*2)%mod;
    }
    cout<<ans<<endl;

    return 0;
}