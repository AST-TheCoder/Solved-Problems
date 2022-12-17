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

ll n,dp[2001][2001],ans;
string s;
vector<pair<ll,ll>> chk;
vector<ll> g[2001];

ll solve(ll i,ll j){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[chk[i].first][chk[j].first]!=-1) return dp[chk[i].first][chk[j].first];
    if(chk[i].second==chk[j].second){
        dp[chk[i].first][chk[j].first]=solve(i+1,j-1)+2;
        return dp[chk[j].first][chk[i].first]=dp[chk[i].first][chk[j].first];
    }
    dp[chk[i].first][chk[j].first]=max(solve(i+1,j),solve(i,j-1));
    return dp[chk[j].first][chk[i].first]=dp[chk[i].first][chk[j].first];
}

void dfs(ll u,ll p){
    chk.pb({u,s[u]});
    ans=max(ans,solve(0,chk.size()-1));

    for(ll i=0;i<g[u].size();i++){
        ll v=g[u][i];
        if(v==p) continue;
        dfs(v,u);
    }
    //for(ll i=0;i<chk.size();i++) cout<<(char)chk[i].second;cout<<endl;
    chk.pop_back();
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ans=0;
        cin>>n;
        cin>>s;
        s="#"+s;

        for(ll i=0;i<=n;i++){
            g[i].clear();
            for(ll j=0;j<=n;j++) dp[i][j]=-1;
        }

        for(ll i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            g[x].pb(y);
            g[y].pb(x);
        }

        for(ll i=1;i<=n;i++){
            dfs(i,-1);
        }
        cout<<ans<<'\n';
    }

    return 0;
}