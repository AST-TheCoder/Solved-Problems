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
        ll n,m,k;
        cin>>n>>m>>k;

        vector<ll> p[n+2],q[n+2];
        for(ll i=1;i<=m;i++){
            ll l,r;
            cin>>l>>r;
            p[l].pb(i);
            q[r+1].pb(i);
        }
        set<ll> x;
        ll ans=0;
        ll c[m+1];
        memset(c,0,sizeof(c));
        vector<pair<ll,ll>> y;
        for(ll i=1;i<=n;i++){
            for(ll j=0;j<p[i].size();j++) x.insert(p[i][j]);
            for(ll j=0;j<q[i].size();j++) x.erase(q[i][j]);
            //cout<<"chk"<<" "<<i<<" "<<x.size()<<endl;

            if(x.size()==0){
                ans++;
                continue;
            }
            if(x.size()==1){
                c[*x.begin()]++;
                continue;
            }
            if(x.size()==2){
                set<ll>::iterator it=x.begin();
                ll u=*it;
                it++;
                ll v=*it;
                y.push_back({u,v});
            }
        }

        sort(all(y));
        ll temp=0;
        for(ll i=0,cx=0;i<y.size();i++){
            if(i && y[i]!=y[i-1]) cx=0;
            //cout<<y[i].first<<" "<<y[i].second<<endl;
            cx++;
            temp=max(temp,cx+c[y[i].first]+c[y[i].second]);
        }

        sort(c,c+m+1,greater<ll>());
        temp=max(temp,c[0]+c[1]);
        ans+=temp;
        cout<<ans<<endl;
    }

    return 0;
}