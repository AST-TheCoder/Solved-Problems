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

    ll t,mod=998244353;
    cin>>t;

    while(t--){
        ll n,x;
        cin>>n>>x;

        ll a[n];
        for(ll i=0,m=1;i<n;i++){
            cin>>a[i];
            a[i]=(a[i]*m)%mod;
            m=(m*x)%mod;
        }

        ll ans=0,s=0;

        for(ll )
    }

    return 0;
}