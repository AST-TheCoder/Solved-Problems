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
    if(p==0) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

int main()
{

    ll n;
    cin>>n;

    ll a[n],s=0,ans=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    s%=mod;

    for(ll i=1;i<=n;i++){
        ans+=(s*bigmod(i,mod-2))%mod;
        ans%=mod;
    }

    cout<<ans<<endl;

    return 0;
}