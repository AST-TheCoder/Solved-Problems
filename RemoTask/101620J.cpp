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

vector<ll> g[1000001];
ll subtree[1000001],cnt[1000001];

void dfs(ll u,ll p){
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==p) continue;
        dfs(v,u);
        subtree[u]+=subtree[v];
    }
    subtree[u]++;
    cnt[subtree[u]]++;
}

int main()
{

    ll n;
    cin>>n;

    for(ll i=1;i<n;i++){
        ll x,y;
        cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    dfs(1,0);

    for(ll i=1;i<n;i++){
        ll x=i+1;
        if(n%x) continue;
        ll comp=n/x,c=0;
        for(ll j=comp;j<=n;j+=comp) c+=cnt[j];
        if(c!=x) continue;
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}