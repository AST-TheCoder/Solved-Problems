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

    ll x,y;
    cin>>x>>y;

    vector<pair<ll,ll>> d;
    for(ll i=1;i*i<=x;i++){
        if(x%i) continue;
        d.pb({y-(y%i),i});
        ll p=x/i;
        if(i==p) continue;
        d.pb({y-(y%p),p});
    }

    sort(all(d),greater<pair<ll,ll>>());
    ll ans=0,p=y,g=1;
    for(ll i=0;i<d.size();i++){
        //cout<<d[i].first<<" "<<d[i].second<<endl;
        if(d[i].first==p){
            g=max(g,d[i].second);
            continue;
        }
        if((p-d[i].first)%g==0){
            ans+=(p-d[i].first)/g;
            g=d[i].second;
            p=d[i].first;
        }
    }
    ans+=p/g;
    cout<<ans<<endl;

    return 0;
}