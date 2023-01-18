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
        
        ll a[n+2];
        for(ll i=0;i<n;i++) cin>>a[i];

        vector<ll> v;
        v.pb(0);
        for(ll i=1,val=abs(a[0]);i<=n;i++){
            if(!a[0]) a[0]=1;
            if(i==n){
                v.pb(val);
                break;
            }
            if(!a[i]){
                a[i]=a[i-1];
                continue;
            }
            if(a[i]/abs(a[i])!=a[i-1]/abs(a[i-1])){
                v.pb(val);
                val=0;
            }
            val+=abs(a[i]);
        }
        v.pb(0);

        ll ans=0;
        for(ll i=1;i<v.size()-1;i++){
            if(ans<=v[i]){
                ans=v[i];
                continue;
            }
            ll p=ans-v[i];
            v[i+1]+=p;
        }

        cout<<ans<<endl;
    }

    return 0;
}