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
        ll n,k;
        cin>>n>>k;
        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        if(k>=3){
            cout<<0<<endl;
            continue;
        }
        sort(a,a+n);
        ll ans=a[0];
        for(ll i=1;i<n;i++){
            ans=min(ans,a[i]-a[i-1]);
        }
        if(k==1){
            cout<<ans<<endl;
            continue;
        }
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ll d=abs(a[j]-a[i]);
                ll id=upper_bound(a,a+n,d)-a;
                if(id!=n) ans=min(ans,a[id]-d);
                if(id) ans=min(ans,d-a[id-1]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}