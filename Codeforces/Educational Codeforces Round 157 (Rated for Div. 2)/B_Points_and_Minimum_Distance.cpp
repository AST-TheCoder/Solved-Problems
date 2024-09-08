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

        ll a[2*n];
        for(ll i=0;i<2*n;i++) cin>>a[i];

        sort(a,a+2*n);
        cout<<a[n-1]-a[0]+a[2*n-1]-a[n]<<endl;
        for(ll i=0;i<n;i++) cout<<a[i]<<" "<<a[i+n]<<endl;
    }

    return 0;
}