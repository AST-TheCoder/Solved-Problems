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

        ll n,m;
        cin>>n>>m;

        ll a[n+1][m+1];
        ll s=0;

        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++){
                cin>>a[i][j];
                s+=a[i][j];
            }
        }

        if(s%n){
            cout<<-1<<endl;
            continue;
        }
        ll d=s/n;

        ll x[n+1];
        memset(x,0,sizeof(x));
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=m;j++) x[i]+=a[i][j];
        }

        vector<pair<pair<ll,ll>,ll>> ans;
        for(ll j=1;j<=m;j++){
            vector<ll> p,q;

            for(ll i=1;i<=n;i++){
                //cout<<i<<" "<<x[i]<<endl;
                if(x[i]>d && a[i][j]==1) p.pb(i);
                if(x[i]<d && a[i][j]==0) q.pb(i);
            }

            for(ll k=0;k<min(p.size(),q.size());k++){
                x[p[k]]--;
                x[q[k]]++;
                ans.pb({{p[k],q[k]},j});
            }
        }

        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;

    }

    return 0;
}