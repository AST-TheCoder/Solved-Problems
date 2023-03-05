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

        ll a[n],b[n];
        pair<ll,ll> x[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        for(ll i=0;i<n;i++){
            cin>>b[i];
            x[i].first=a[i]+b[i];
            x[i].second=i;
        }
        sort(x,x+n);
        ll c[n];
        for(ll i=0;i<n;i++){
            c[i]=x[i].first;
            if(i) c[i]+=c[i-1];
        }

        ll ans=upper_bound(c,c+n,k)-c;
        for(ll i=0;i<n;i++){
            ll id=x[i].second;
            if(a[id]>k) continue;
            ll temp=k-a[id];
            ll cnt=upper_bound(c,c+n,temp)-c;
            //cout<<id<<" "<<cnt<<endl;
            if(cnt>=i+1){
                temp=k+b[id];
                cnt=upper_bound(c,c+n,temp)-c;
                ans=max(ans,cnt);
            }
            else ans=max(ans,cnt+1);
        }
        cout<<ans<<endl;
    }

    return 0;
}