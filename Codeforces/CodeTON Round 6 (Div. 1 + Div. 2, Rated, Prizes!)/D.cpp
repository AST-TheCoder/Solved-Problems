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
        ll k,d=1,ans[n+1],prev=Max;
        cin>>k;

        vector<ll> x;
        for(ll i=n;i>=1;i--){
            ans[i]=0;
            ll p=k/a[i];
            if(p>d){
                x.pb(i);
                d=p;
                prev=a[i];
            }
            if(p==d && prev>a[i]){
                x.pb(i);
                prev=a[i];
            }
        }

        if(!x.size()){
            for(ll i=0;i<n;i++) cout<<0<<" ";
            cout<<endl;
            continue;
        }

        reverse(all(x));
        ans[x[0]]=k/a[x[0]];
        d=k%a[x[0]];
        for(ll i=1;i<x.size();i++){
            ll p=a[x[i]]-a[x[i-1]];
            if(p>d) break;
            ll m=min(ans[x[i-1]],d/p);
            ans[x[i]]=m;
            d-=(m*p);
        }
        d=0;
        for(ll i=n;i>=1;i--){
            d=max(d,ans[i]);
            ans[i]=d;
        }
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}