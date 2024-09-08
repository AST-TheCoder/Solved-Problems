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
        ll n,m;
        cin>>n>>m;
        ll a[n],b[n];
        a[0]=1;
        for(ll i=1;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++) cin>>b[i];

        multiset<ll> x;
        for(ll i=0;i<n;i++){
            x.insert(b[i]);
        }
        ll ans=0;
        sort(a,a+n);
        for(ll i=0;i<n;i++){
            multiset<ll>::iterator it=x.upper_bound(a[i]);
            if(it==x.end()) ans++;
            else x.erase(it);
        }
        cout<<ans<<endl;
    }

    return 0;
}