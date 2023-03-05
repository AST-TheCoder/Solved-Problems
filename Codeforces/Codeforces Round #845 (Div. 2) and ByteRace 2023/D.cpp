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

vector<ll> g[200007];
ll lev[200007],cnt[200007];
void dfs(ll u,ll p){
    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==p) continue;
        dfs(v,u);
        lev[u]=max(lev[u],lev[v]);
    }
    lev[u]++;
    cnt[lev[u]]++;
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n,mod=1000000007,p=1,ans=0;
        cin>>n;

        for(ll i=0;i<=n;i++){
            g[i].clear();
            lev[i]=0;
            cnt[i]=0;
        }

        for(ll i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
            p=(p*2)%mod;
        }

        dfs(1,-1);
        for(ll i=n,s=0;i>=1;i--){
            s+=cnt[i];
            ll temp=(s*p)%mod;
            ans=(ans+temp)%mod;
        }
        cout<<ans<<endl;
    }

    return 0;
}