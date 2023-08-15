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

        ll a[n],b[n];
        ll x=(1LL<<35)-1;
        for(ll i=0;i<n;i++){
            ll p;
            cin>>p;
            x&=p;
            a[i]=x;
            b[i]=p;
        }
        if(x){
            cout<<1<<endl;
            continue;
        }
        x=(1LL<<35)-1;
        ll ans=1;
        for(ll i=n-1;i>=1;i--){
            x&=b[i];
            if(!x && !a[i-1]){
                ans++;
                x=(1LL<<35)-1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}