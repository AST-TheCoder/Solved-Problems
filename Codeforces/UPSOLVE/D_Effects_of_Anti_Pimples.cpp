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

ll p[100001];
int main()
{

    ll mod=998244353;
    ll n;
    cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++) cin>>a[i];
    for(ll i=n;i>=1;i--){
        for(ll j=2*i;j<=n;j+=i){
            a[i]=max(a[i],a[j]);
        }
    }

    p[0]=1;
    for(ll i=1;i<=100000;i++){
        p[i]=(p[i-1]*2)%mod;
    }

    ll ans=0;
    sort(a+1,a+n+1,greater<ll>());
    for(ll i=1;i<=n;i++){
        ll temp=(a[i]*p[n-i])%mod;
        ans=(ans+temp)%mod;
    }
    cout<<ans<<endl;

    return 0;
}