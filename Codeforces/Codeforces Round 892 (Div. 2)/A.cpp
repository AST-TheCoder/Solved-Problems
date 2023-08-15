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
        sort(a,a+n);
        if(a[0]==a[n-1]){
            cout<<-1<<endl;
            continue;
        }

        vector<ll> x,y;
        for(ll i=n-1;i>=0;i--){
            if(a[i]==a[n-1]) y.pb(a[i]);
            else x.pb(a[i]);
        }
        cout<<x.size()<<" "<<y.size()<<endl;
        for(ll i=0;i<x.size();i++) cout<<x[i]<<" ";cout<<endl;
        for(ll i=0;i<y.size();i++) cout<<y[i]<<" ";cout<<endl;
    }

    return 0;
}