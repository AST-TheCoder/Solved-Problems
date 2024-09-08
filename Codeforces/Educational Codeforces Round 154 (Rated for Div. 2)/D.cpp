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
        for(ll i=1;i<=n;i++) cin>>a[i];
        if(n==1){
            cout<<0<<endl;
            continue;
        }

        ll c=0;
        for(ll i=2;i<=n;i++) if(a[i]<=a[i-1]) c++;
        ll ans=c,d=1;
        if(a[1]>=a[2]) c--;
        for(ll i=2;i<n;i++){
            if(a[i]>=a[i+1]) c--;
            if(a[i]>=a[i-1]) d++;
            ans=min(ans,c+d);
        }

        cout<<ans<<endl;
    }

    return 0;
}