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

        vector<pair<ll,ll>> v;
        for(ll i=0;i<n;i++){
            ll l,r,a,b;
            cin>>l>>r>>a>>b;
            v.pb({b,l});
        }

        sort(all(v),greater<pair<ll,ll>>());

        ll q;
        cin>>q;
        ll ans[q];
        vector<pair<ll,ll>> pos;
        for(ll i=0;i<q;i++){
            ll temp;
            cin>>temp;
            pos.pb({temp,i});
            ans[i]=temp;
        }
        sort(all(pos),greater<pair<ll,ll>>());

        ll mx=v[0].first,lf=v[0].second;
        for(ll i=0,j=0;i<n;i++){
            if(i && v[i].first<lf){
                mx=v[i].first;
                lf=v[i].second;
            }
            else lf=min(lf,v[i].second);
            for(;j<q && pos[j].first>=lf;j++){
                if(pos[j].first<mx) ans[pos[j].second]=mx;
            }
        }

        for(ll i=0;i<q;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}