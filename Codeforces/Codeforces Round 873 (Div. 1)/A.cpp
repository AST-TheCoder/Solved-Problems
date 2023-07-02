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

    ll t;
    cin>>t;
    read:
    while(t--){
        ll n;
        cin>>n;

        ll a[n],b[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];

        sort(a,a+n);
        sort(b,b+n);
        for(ll i=0;i<n;i++){
            if(a[i]<=b[i]){
                cout<<0<<endl;
                //cout<<i<<" "<<a[i]<<" "<<b[i]<<endl;
                goto read;
            }
        }

        ll ans=1,mod=1000000007;

        for(ll i=0;i<n;i++){
            ll id=lower_bound(b,b+n,a[i])-b;
            ans*=(id-i);
            ans%=mod;
        }

        cout<<ans<<endl;
    }

    return 0;
}