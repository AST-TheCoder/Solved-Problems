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

bool chk[300000];
vector<ll> pr;

int main()
{

    for(ll i=2;i<300000;i++){
        if(!chk[i]){
            pr.pb(i);
            for(ll j=i;j<300000;j+=i) chk[j]=1;
        }
    }

    ll t;
    cin>>t;

    while(t--){
        ll n,ans=0;
        cin>>n;

        vector<ll> s;
        for(ll i=0;i<n;i++){
            ll x,y;
            cin>>x>>y;
            
            vector<ll> temp;
            for(auto v: s){
                if(v%y){
                    continue;
                }
                ll d=v/y;
                if(x%d) continue;
                temp.pb(v);
            }

            s.clear();
            s=temp;

            if(s.size()) continue;
            ans++;
            vector<pair<ll,ll>> p;
            //cout<<"ok"<<endl;
            for(ll j=0;pr[j]*pr[j]<=x;j++){
                if(x%pr[j]) continue;
                ll cnt=0;
                while(x%pr[j]==0){
                    cnt++;
                    x/=pr[j];
                }
                p.pb({pr[j],cnt});
            }
            if(x!=1){
                p.pb({x,1});
            }
            //cout<<"ok"<<endl;
            vector<ll> d;
            d.pb(1);
            for(ll j=0;j<p.size();j++){
                ll sz=d.size();
                for(ll k=1,v=p[j].first;k<=p[j].second;k++,v*=p[j].first){
                    //cout<<k<<" "<<v<<endl;
                    for(ll l=0;l<sz;l++){
                        d.pb(d[l]*v);
                    }
                }
            }
            for(ll j=0;j<d.size();j++) s.pb(d[j]*y);
        }
        cout<<ans<<"\n";
    }

    return 0;
}