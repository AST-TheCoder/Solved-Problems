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

ll a[200001];

int main()
{

    ll n,q;
    cin>>n>>q;

    ll p[n+1];
    for(ll i=1;i<=n;i++){
        cin>>p[i];
    }

    for(ll i=2;i<n;i++){
        if((p[i-1]>=p[i] && p[i]>=p[i+1])) a[i]=1;
    }

    for(ll i=2;i<=n;i++){
        a[i]+=a[i-1];
    }

    while(q--){
        ll l,r;
        cin>>l>>r;
        cout<<(r-l+1)-((r!=l)?a[r-1]-a[l]:0)<<"\n";
    }

    return 0;
}