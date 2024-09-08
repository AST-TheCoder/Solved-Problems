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
        ll n,m,d;
        cin>>n>>m>>d;
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];

        min_heap<ll> p;
        ll ans=0,s=0;
        for(ll i=1;i<=n;i++){
            if(a[i]<0) continue;
            if(p.size()==m && a[i]>p.top()){
                s-=p.top();
                p.pop();
                s+=a[i];
                p.push(a[i]);
            }
            if(p.size()<m){
                s+=a[i];
                p.push(a[i]);
            }
            ans=max(ans,s-i*d);
        }
        cout<<ans<<endl;
    }

    return 0;
}