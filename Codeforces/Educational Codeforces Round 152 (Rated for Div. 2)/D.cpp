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

    ll n;
    cin>>n;

    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];

    ll ans=0;
    for(ll i=0;i<n;i++){
        if(a[i]!=2) continue;
        ans++;
        for(ll j=i-1;j>=0;j--){
            ll x=a[j];
            a[j]=-1;
            if(x<=0) break;
        }
        for(ll j=i+1;j<n;j++){
            ll x=a[j];
            a[j]=-1;
            if(x<=0) break;
        }
        a[i]=-1;
    }

    for(ll i=0;i<n;i++){
        if(a[i]!=1) continue;
        if(!i || a[i-1]<=0) ans++;
    }
    //cout<<ans<<endl;

    for(ll i=0;i<n;i++){
        if(a[i]!=0) continue;
        if(i && a[i-1]==1){
            a[i]=-1;
            for(ll j=i-1;j>=0;j--){
                if(a[j]!=1) break;
                a[j]=-1;
            }
            continue;
        }
        if(i+1!=n && a[i+1]==1){
            a[i]=-1;
            for(ll j=i+1;j<n;j++){
                if(a[j]!=1) break;
                a[j]=-1;
            }
            continue;
        }
        ans++;
        a[i]=-1;
    }
    cout<<ans<<endl;

    return 0;
}