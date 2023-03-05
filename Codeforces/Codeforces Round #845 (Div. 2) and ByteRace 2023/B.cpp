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

    ll fact[100001],mod=1000000007;

    fact[0]=1;
    for(ll i=1;i<=100000;i++) fact[i]=(fact[i-1]*i)%mod;

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll ans=0;
        for(ll i=1;i<n;i++){
            ll temp=2*i;
            temp=(temp*fact[n])%mod;
            ans=(ans+temp)%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}