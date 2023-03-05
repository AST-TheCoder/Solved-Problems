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

    vector<pair<ll,ll>> val;
    for(ll i=1;i<=2000000;i++){
        ll v=i*i*i-1;
        v=sqrt(v);
        v=v-(i-1);
        val.pb({v,i*i*i});
    }

    while(t--){
        ll x;
        cin>>x;
        pair<ll,ll> v={x,-1};
        ll id=lower_bound(all(val),v)-val.begin();
        ll l=val[id-1].second+1;
        ll r=val[id].second-1;

        ll ans=r;
        while(l<=r){
            ll m=(l+r)/2;
            ll p=sqrt(m);
            ll q=cbrt(m);
            if(p-q>=x){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        cout<<ans<<endl;
    }

    return 0;
}