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
        ll a,b;
        cin>>a>>b;
        if(a>b) swap(a,b);

        ll ans=a+b;

        vector<ll> p,q;
        for(ll i=1;i<=sqrt(a);i++){
            if(a%i==0){
                p.pb(i);
                if(i!=a/i) p.pb(a/i);
            }
        }
        sort(all(p));

        for(ll i=1;i<=sqrt(b);i++){
            if(b%i==0){
                q.pb(i);
                if(i!=b/i) q.pb(b/i);
            }
        }
        sort(all(q));

        for(ll i=0;i<p.size();i++){
            ll x=p[i];
            for(ll id=0;id<q.size() && q[id]<=p[i];id++){
                ll y=q[id];
                ans=min(ans,x+a/x+b/y-1);
            }
        }

        for(ll i=0;i<q.size();i++){
            ll x=q[i];
            for(ll id=0;id<p.size() && p[id]<=q[i];id++){
                ll y=p[id];
                ans=min(ans,x+b/x+a/y-1);
            }
        }

        cout<<ans<<"\n";

    }

    return 0;
}