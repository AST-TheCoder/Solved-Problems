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

        vector<ll> a[k+1];
        for(ll i=1;i<=k;i++) a[i].pb(0);
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
            a[x].pb(i);
        }
        ll ans=n;
        for(ll i=1;i<=k;i++){
            a[i].pb(n+1);
            ll x=-1,y=-1;
            for(ll j=1;j<a[i].size();j++){
                ll d=a[i][j]-a[i][j-1]-1;
                if(x==-1) x=d;
                else if(d>=x) y=x,x=d;
                else if(d>=y) y=d;
            }
            x/=2;
            ans=min(ans,max(x,y));
        }
        cout<<ans<<endl;
    }

    return 0;
}