#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 1000000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll m;
        cin>>m;

        vector<pair<pair<ll,ll>,pair<ll,ll>>> v;
        ll mn=0,mx=0;

        for(ll i=1;i<=m;i++){
            ll n,l,r,c=0;
            cin>>n>>l>>r;
            mn+=l;
            mx+=r;
            vector<ll> a,b;
            for(ll j=0;j<n;j++){
                ll x;
                cin>>x;
                a.pb(x);
            }
            for(ll j=0;j<n;j++){
                ll x;
                cin>>x;
                c+=x;
                b.pb(x);
            }
            for(ll j=0;j<n;j++){
                ll x=c-b[j];
                if(x>r) x=r;
                if(x<l) x=l;
                v.pb({{a[j],min(c-b[j],r)},{l,r-x}});
            }
        }
        v.pb({{Max,-1},{-1,-1}});
        sort(all(v));

        ll ans=Max,cnt=0;
        for(ll i=1,temp=0,len=mx;i<v.size();i++){
            if(v[i-1].first.second<v[i-1].second.first) temp+=v[i-1].second.first-v[i-1].first.second;
            len-=v[i-1].second.second;
            if(v[i].first.first==v[i-1].first.first) continue;

            if(v[i-1].first.first>=mn && v[i-1].first.first<=mx){
                if(len<v[i-1].first.first) temp+=v[i-1].first.first-len;
                cnt++;
                ans=min(ans,temp);
            }
            temp=0,len=mx;
        }
        if(cnt!=mx-mn+1) ans=0;
        cout<<ans<<endl;
    }

    return 0;
}