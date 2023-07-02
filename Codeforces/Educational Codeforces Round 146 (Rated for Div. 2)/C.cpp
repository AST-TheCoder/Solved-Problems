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
        ll n,p,q;
        cin>>n>>p>>q;
        pair<ll,ll> a[n];
        vector<ll> x,y;
        for(ll i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i+1;
        }
        sort(a,a+n,greater<pair<ll,ll>>());

        for(ll i=0;i<n;i++){
            ll u=(x.size()+1)*p;
            ll v=(y.size()+1)*q;
            if(u<=v) x.pb(a[i].second);
            else y.pb(a[i].second);
        }

        cout<<x.size();for(ll i=0;i<x.size();i++) cout<<" "<<x[i];cout<<endl;
        cout<<y.size();for(ll i=0;i<y.size();i++) cout<<" "<<y[i];cout<<endl;
    }

    return 0;
}