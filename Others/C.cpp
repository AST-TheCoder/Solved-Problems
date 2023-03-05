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

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n,m,p,qq;
        cin>>n>>m>>p>>qq;

        vector<pair<ll,ll>> g[n];
        for(ll i=0;i<m;i++){
            ll u,v,w;
            cin>>u>>v>>w;
            g[u].pb({v,w});
            g[v].pb({u,w});
        }

        ll dis[n];
        memset(dis,-1,sizeof(dis));
        min_heap<pair<ll,ll>> q;
        dis[p]=0;
        q.push({0,p});

        while(!q.empty()){
            ll u=q.top().second;
            q.pop();
            for(ll i=0;i<g[u].size();i++){
                ll v=g[u][i].first;
                ll w=g[u][i].second;
                if(dis[v]!=-1 && dis[v]<=dis[u]+w) continue;
                //cout<<u<<" "<<v<<" "<<w<<endl;
                dis[v]=dis[u]+w;
                q.push({dis[v],v});
            }
        }

        cout<<"Case #"<<++ii<<": ";
        if(dis[qq]==-1) cout<<"unreachable"<<endl;
        else cout<<dis[qq]<<endl;
    }

    return 0;
}