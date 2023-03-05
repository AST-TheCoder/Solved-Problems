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

vector<pair<ll,pair<ll,ll>>> edges,mst;
vector<pair<ll,ll>> g[15];
ll par[15],vis[15];

ll find_par(ll x){
    if(par[x]==x) return x;
    return par[x]=find_par(par[x]);
}

void dsu(ll u,ll v,ll w){
    ll x=find_par(u);
    ll y=find_par(v);

    if(x!=y){
        mst.pb({w,{u,v}});
        par[x]=y;
    }
}

ll dfs(ll u,ll s){
    vis[u]=1;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i].first;
        ll w=g[u][i].second;
        if(vis[v]) continue;
        s+=dfs(v,0)+w;
    }
    return s;
}

int main()
{

    ll n,c,m;
    cin>>n>>c>>m;

    for(ll i=0;i<m;i++){
        ll u,v,w;
        cin>>u>>v>>w;

        edges.pb({w,{u,v}});
    }
    for(ll i=0;i<n;i++) par[i]=i;
    sort(all(edges));

    for(ll i=0;i<m;i++){
        dsu(edges[i].second.first,edges[i].second.second,edges[i].first);
    }

    ll p=pow(2,mst.size()),ans=Max;
    for(ll i=0;i<p;i++){
        for(ll j=0;j<n;j++){
            g[j].clear();
            vis[j]=0;
        }
        for(ll j=0;j<mst.size();j++){
            if(i&(1<<j)){
                ll u,v,w;
                u=mst[j].second.first;
                v=mst[j].second.second;
                w=mst[j].first;
                g[u].pb({v,w});
                g[v].pb({u,w});
            }
        }
        ll mx=0,comp=0;
        for(ll j=0;j<n;j++){
            if(vis[j]) continue;
            comp++;
            mx=max(dfs(j,0),mx);
        }
        if(comp<=c) ans=min(ans,mx);
    }
    if(ans==Max) ans=-1;
    cout<<ans<<endl;

    return 0;
}