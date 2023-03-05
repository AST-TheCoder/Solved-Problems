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

vector<pair<ll,ll>> g[1000001];
ll a[1000001];

ll dfs(ll u,ll p){
    ll ret=a[u];
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i].first,w=g[u][i].second;
        if(v==p) continue;
        ret+=min(dfs(v,u),w);
    }
    return ret;
}

int main()
{

    ll n,s;
    cin>>n>>s;

    for(ll i=1;i<n;i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    for(ll i=1;i<=n;i++) cin>>a[i];

    ll ans=dfs(s,0);
    cout<<ans<<endl;

    return 0;
}