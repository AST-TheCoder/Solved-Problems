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

    while(t--){
        ll n;
        cin>>n;

        vector<ll> x,y;
        for(ll i=0;i<n;i++){
            ll p;
            cin>>p;
            ll a[p];
            for(ll j=0;j<p;j++) cin>>a[j];
            sort(a,a+p);
            x.pb(a[0]);
            y.pb(a[1]);
        }

        ll ans=0;
        sort(all(x));
        sort(all(y));

        for(ll i=0;i<n;i++) ans+=y[i];
        ans-=y[0];
        ans+=x[0];
        cout<<ans<<endl;
    }

    return 0;
}