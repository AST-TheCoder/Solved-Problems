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

ll n,ans=0,c[5001];
vector<ll> g[5001];

void dfs(ll u,ll p){
    ll dp[n+1];
    memset(dp,0,sizeof(dp));
    vector<ll> a;
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==p) continue;
        dfs(v,u);
        a.pb(c[v]);
        c[u]+=c[v];
    }

    dp[0]=1;
    for(ll i=0;i<a.size();i++){
        for(ll j=n;j>=1;j--){
            if(j<a[i]) break;
            if(dp[j-a[i]]) dp[j]=dp[j-a[i]];
        }
    }

    ll mx=0;
    for(ll i=1;i<=n;i++){
        if(!dp[i]) continue;
        mx=max(mx,i*(c[u]-i));
    }
    ans+=mx;
    c[u]++;
}

int main()
{

    cin>>n;
    for(ll i=2;i<=n;i++){
        ll x;
        cin>>x;
        g[x].pb(i);
        g[i].pb(x);
    }

    dfs(1,0);
    cout<<ans<<endl;

    return 0;
}