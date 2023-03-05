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

int main()
{

    ll n;
    cin>>n;

    ordered_set<ll> a;
    ll p[n+1],mod=1000000007;
    a.insert(-Max);
    p[0]=1;
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        a.insert(x);
        p[i]=(2*p[i-1])%mod;
    }

    ll ans=0;
    for(ll i=2;i<=n;i++){
        ll u=*a.find_by_order(i);
        for(ll j=i-1;j>=1;j--){
            ll v=*a.find_by_order(j);
            ll d=u-v;
            ll r1=a.order_of_key(v-d)-1;
            ll r2=n-a.order_of_key(u+d)+1;
            ans=(ans+p[r1+r2])%mod;
        }
    }
    cout<<ans<<endl;

    return 0;
}