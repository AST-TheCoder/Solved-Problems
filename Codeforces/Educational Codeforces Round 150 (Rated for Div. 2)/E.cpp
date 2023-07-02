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

        ll a[n+1];
        vector<pair<ll,ll>> v;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            v.pb({a[i],i});
        }
        v.pb({n,0});
        v.pb({0,n+1});
        sort(all(v),greater<pair<ll,ll>>());
        set<pair<ll,ll>> x;
        x.insert({1,n});
        ll ans=0;
        ll m;
        cin>>m;
        ll s=n-1;
        if(n==1){
            cout<<0<<endl;
            continue;
        }

        for(ll i=1;i<v.size();i++){
            
        }
    }

    return 0;
}