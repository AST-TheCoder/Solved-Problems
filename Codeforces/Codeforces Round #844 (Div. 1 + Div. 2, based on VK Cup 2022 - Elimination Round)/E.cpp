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

        vector<pair<pair<ll,ll>,ll>> x,y;
        vector<pair<pair<ll,ll>,pair<ll,ll>>> v;
        for(ll i=0;i<n;i++){
            ll a,b,p,q;
            cin>>a>>b>>p>>q;
            v.pb({{0,0},{0,0}});

            if(a==p){
                if(a==1) x.pb({{b,-q},i});
                else y.pb({{b,-q},i});
            }
            else{
                x.pb({{b,-q},i});
                y.pb({{b,-q},i});
            }
        }

        ll ans=0;
        
        sort(all(x));
        sort(all(y));

        ll mc=0;

        for(ll i=0;i<x.size();i++){
            mc=max(mc,x[i].first.first);
            x[i].first.second*=-1;
            ll d=x[i].first.second-mc+1;
            if(d<=0) continue;
            v[x[i].second]={{1,x[i].first.first},{1,x[i].first.second}};
            mc=x[i].first.second+1;
            ans+=d;
        }

        mc=0;
        for(ll i=0;i<y.size();i++){
            mc=max(mc,y[i].first.first);
            y[i].first.second*=-1;
            ll d=y[i].first.second-mc+1;
            if(d<=0) continue;
            if(v[y[i].second].first.first) v[y[i].second].second.first=2;
            else v[y[i].second]={{2,y[i].first.first},{2,y[i].first.second}};
            mc=y[i].first.second+1;
            ans+=d;
        }

        x.clear();
        y.clear();

        for(ll i=0;i<n;i++){
            if(v[i].first.first==v[i].second.first){
                if(v[i].first.first==1) x.pb({{v[i].first.second,v[i].second.second},i});
                if(v[i].first.first==1) y.pb({{v[i].first.second,v[i].second.second},i});
            }
            else{
                x.pb({{v[i].first.second,v[i].second.second},i});
                y.pb({{v[i].first.second,v[i].second.second},i});
            }
        }

        sort(all(x));
        sort(all(y));
        mc=0;
        for(ll i=0;i<(ll)x.size();i++){
            ll id=x[i].second;
        }

        cout<<ans<<endl;
        for(ll i=0;i<n;i++) cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second.first<<" "<<v[i].second.second<<endl;

    }

    return 0;
}