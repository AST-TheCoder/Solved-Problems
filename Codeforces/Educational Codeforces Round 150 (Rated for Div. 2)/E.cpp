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
        vector<pair<ll,ll>> v;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            v.pb({a[i],i});
        }
        sort(all(v),greater<pair<ll,ll>>());
        vector<pair<ll,ll>> rec;
        ordered_set<pair<pair<ll,ll>,ll>> ran;
        ran.insert({{1,n},n});
        for(ll i=0;i<n;i++){
            ll id=ran.order_of_key({{v[i].second+1,-1},-1});
            id--;
            pair<pair<ll,ll>,ll> val=*ran.find_by_order(id);
            ran.erase(ran.find_by_order(id));
            if(val.first.first<v[i].second) ran.insert({{val.first.first,v[i].second-1},v[i].first});
            if(val.first.second>v[i].second) ran.insert({{v[i].second+1,val.first.second},v[i].first});
            if(v[i].first!=val.second){
                rec.pb({val.first.second-val.first.first+1,val.second-v[i].first});
                //cout<<val.first.first<<" "<<val.first.second<<" "<<val.second<<" "<<v[i].first<<endl;
            }
        }
        sort(all(rec),greater<pair<ll,ll>>());
        ll m;
        cin>>m;
        ll ans=0;
        for(ll i=0;i<rec.size();i++){
            if(rec[i].first*rec[i].second<=m){
                m-=rec[i].first*rec[i].second;
                ans+=(rec[i].first-1)*rec[i].second;
                continue;
            }
            ll temp=m/rec[i].first;
            ans+=temp*(rec[i].first-1);
            m%=rec[i].first;
            if(m) ans+=(m-1);
            break;
        }

        cout<<ans<<endl;
    }

    return 0;
}