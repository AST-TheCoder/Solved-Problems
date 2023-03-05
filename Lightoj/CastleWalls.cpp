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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        ordered_set<ll> s;
        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++){
            ll l,r;
            cin>>l>>r;
            v.pb({l,r});
        }
        for(ll i=0;i<m;i++){
            ll l,r;
            cin>>l>>r;
            v.pb({l,r});
        }
        sort(all(v));
        ll ans=0;
        for(ll i=0;i<n+m;i++){
            ll len=s.order_of_key(v[i].second);
            len=s.size()-len;
            ans+=len;
            s.insert(v[i].second);
        }
        cout<<"Case "<<++ii<<": "<<ans<<endl;
    }

    return 0;
}