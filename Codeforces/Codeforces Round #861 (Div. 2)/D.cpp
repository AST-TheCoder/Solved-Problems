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

ordered_set<ll> p[200001][2];

int main()
{

    ll n,k;
    cin>>n>>k;

    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        p[a[i]][i%2].insert(i);
    }

    if(k==1){
        cout<<0<<endl;
        return 0;
    }

    ll ans=0;
    for(ll i=0;i<n-(k-2);i++){
        ll l=max(i,k-(2*i+1));
        ll r=min(i+k-1,n-1);
        if(r%2!=i%2) r--;
        //if(r<l) continue;
        ll c1=p[a[i]][i%2].order_of_key(l);
        ll c2=p[a[i]][i%2].order_of_key(r+1);
        ll c=c2-c1;
        ll x=(r-l)/2+1;
        //cout<<i<<" "<<l<<" "<<r<<" "<<c1<<" "<<c2<<" "<<c<<" "<<x<<endl;
        ans+=x-c;
    }
    cout<<ans<<endl;

    return 0;
}