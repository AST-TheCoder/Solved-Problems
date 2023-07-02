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

map<ll,ll> cnt;

int main()
{

    ll n,m,k;
    cin>>n>>m>>k;

    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    sort(a,a+n);
    if(k==1){
        ll ans=0;
        for(ll i=0;i<n;i++){
            if(a[i]==ans) ans++;
        }
        if(ans>m) cout<<0<<" "<<0<<endl;
        else cout<<1<<" "<<ans<<endl;
        return 0;
    }

    ll id=lower_bound(a,a+n,0)-a;
    id=id+k-1;
    ll mx,ans=0;
    if(cnt[0]>=k) mx=0;
    else mx=(a[id]-1)/2+1;
    //cout<<0<<" "<<mx<<endl;

    for(ll i=0;i<n;i++){
        id=lower_bound(a,a+n,a[i])-a;
        ll x=id+k-1;
        ll y=id-k;
        if(id<n && a[id]==a[i]){
            y++;
            if(cnt[a[id]]>=k) continue;
        }
        if(x>=n) x=m;
        else{
            x=(a[x]+a[i]-1)/2;
        }
        if(y<0) y=0;
        else{
            y=(a[y]+a[i]+1)/2;
        }
        if((x-y+1)>mx){
            mx=(x-y+1);
            ans=a[i];
        }
    }
    for(ll i=0;i<n;i++){
        if(a[i]+1>m) continue;
        id=lower_bound(a,a+n,a[i]+1)-a;
        ll x=id+k-1;
        ll y=id-k;
        if(id<n && a[id]==a[i]+1){
            y++;
            if(cnt[a[id]]>=k) continue;
        }
        if(x>=n) x=m;
        else{
            x=(a[x]+a[i])/2;
        }
        if(y<0) y=0;
        else{
            y=(a[y]+a[i]+2)/2;
        }
        if((x-y+1)>mx){
            mx=(x-y+1);
            ans=a[i]+1;
        }
        //cout<<a[i]+1<<" "<<y<<" "<<x<<" "<<x-y+1<<endl;
    }

    for(ll i=0;i<n;i++){
        if(a[i]-1<0) continue;
        id=lower_bound(a,a+n,a[i]-1)-a;
        ll x=id+k-1;
        ll y=id-k;
        if(id<n && a[id]==a[i]-1){
            y++;
            if(cnt[a[id]]>=k) continue;
        }
        if(x>=n) x=m;
        else{
            x=(a[x]+a[i]-2)/2;
        }
        if(y<0) y=0;
        else{
            y=(a[y]+a[i])/2;
        }
        if((x-y+1)>mx){
            mx=(x-y+1);
            ans=a[i]-1;
        }
        //cout<<a[i]+1<<" "<<y<<" "<<x<<" "<<x-y+1<<endl;
    }

    cout<<mx<<" "<<ans<<endl;

    return 0;
}