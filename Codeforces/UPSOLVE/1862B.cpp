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

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];

        vector<ll> v;
        v.pb(a[0]);
        for(ll i=1;i<n;i++){
            v.pb(a[i]);
            if(a[i]<a[i-1]) v.pb(a[i]);
        }
        cout<<v.size()<<endl;
        for(ll i=0;i<v.size();i++) cout<<v[i]<<" ";
        cout<<endl;
    }

    return 0;
}