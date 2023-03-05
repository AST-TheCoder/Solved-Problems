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

    ll n,k;
    cin>>n>>k;

    ll a[n+1];
    for(ll i=1;i<=n;i++) cin>>a[i];

    ll l=1,r=n,ans=-1;
    while(l<=r){
        ll m=(l+r)/2;
        ll cnt=0;
        for(ll i=m;i<=n;i++){
            if(a[m]%a[i]==0) cnt++;
        }
        if(cnt>=k){
            ans=m;
            l=m+1;
        }
        else r=m-1;
    }
    cout<<ans<<endl;

    return 0;
}