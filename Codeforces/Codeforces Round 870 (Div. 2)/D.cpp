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
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        ll x[n+1],y[n+1];
        priority_queue<ll> q;
        q.push(a[n]-n);
        x[n]=0;
        for(ll i=n-1;i>=1;i--){
            ll v=q.top()+i;
            x[i]=v;
            q.push(a[i]-i);
        }
        while(!q.empty()) q.pop();
        q.push(a[1]-n);
        y[1]=0;
        for(ll i=2;i<=n;i++){
            ll v=q.top()+(n-i+1);
            y[i]=v;
            q.push(a[i]-(n-i+1));
        }
        ll ans=0;
        //for(ll i=1;i<=n;i++) cout<<i<<" "<<x[i]<<" "<<y[i]<<endl;
        for(ll i=2;i<n;i++) ans=max(ans,x[i]+y[i]+a[i]);
        cout<<ans<<"\n";
    }

    return 0;
}