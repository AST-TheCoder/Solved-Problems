#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

ll a[501][5001],par[5001];
long long int dis[5001];

vector<long long int> mask[5001];

int main()
{

    ll m,n;
    scanf("%d %d",&m,&n);

    for(ll i=1;i<=n;i++){
        for(ll j=0;j<n/64+5;j++){
            mask[i].pb(0);
        }
        mask[i][i/64]|=(1LL<<(i%64));
    }

    vector<ll> g[n+1];
    ll d[n+1];

    long long int p[n+1];
    for(ll i=1;i<=n;i++){
        scanf("%lli",&p[i]);
        d[i]=0;
        par[i]=-1;
    }

    for(ll i=1;i<=m;i++){
        for(ll j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }

    for(ll i=1;i<=m;i++){
        vector<long long int> temp;
        for(ll j=0;j<n/64+5;j++) temp.pb(0);

        vector<pair<ll,ll>> val;
        for(ll j=1;j<=n;j++) val.pb({a[i][j],j});
        sort(all(val));

        vector<ll> x;
        x.pb(val[0].second);
        temp[val[0].second/64]|=(1LL<<(val[0].second%64));
        for(ll j=1;j<val.size();j++){
            if(val[j].first==val[j-1].first){
                x.pb(val[j].second);
                temp[val[j].second/64]|=(1LL<<(val[j].second%64));
                continue;
            }
            for(ll k=0;k<x.size();k++){
                for(ll l=0;l<temp.size();l++){
                    mask[x[k]][l]|=temp[l];
                }
            }
            x.clear();
            x.pb(val[j].second);
            temp[val[j].second/64]|=(1LL<<(val[j].second%64));
        }
        for(ll k=0;k<x.size();k++){
            for(ll l=0;l<temp.size();l++){
                mask[x[k]][l]|=temp[l];
            }
        }
    }

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            if(mask[i][j/64]&(1LL<<(j%64))) continue;
            g[i].pb(j);
            d[j]++;
        }
    }

    queue<ll> q;
    long long int ans=0;
    for(ll i=1;i<=n;i++){
        if(!d[i]){
            q.push(i);
            dis[i]=p[i];
            ans=max(ans,p[i]);
        }
    }

    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for(ll i=0;i<g[u].size();i++){
            ll v=g[u][i];
            d[v]--;
            if(dis[v]>dis[u]+p[v]){
                if(!d[v]) q.push(v);
                continue;
            }
            dis[v]=dis[u]+p[v];
            if(!d[v]) q.push(v);
            ans=max(ans,dis[v]);
        }
    }

    printf("%lli\n",ans);

    return 0;
}