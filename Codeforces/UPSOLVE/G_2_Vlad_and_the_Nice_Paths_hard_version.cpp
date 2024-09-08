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

pair<ll,ll> dp[5002];
vector<ll> pos[5001];
ll n,k,a[5001],mod=1000000007,fact[5001],inv[5001];

ll bigmod(ll n,ll p){
    if(!p) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

void solve(ll p){
    if(p>n) return;
    if(dp[p].first!=-1) return;
    dp[p]={0,1};
    solve(p+1);
    if(dp[p+1].first>dp[p].first) dp[p]=dp[p+1];
    else if(dp[p+1].first==dp[p].first && dp[p].first!=0) dp[p].second=(dp[p].second+dp[p+1].second)%mod;

    ll idx=lower_bound(all(pos[a[p]]),p)-pos[a[p]].begin();
    for(ll i=idx+k-1;i<pos[a[p]].size();i++){
            ll len=i-idx;
            ll f=(fact[len-1]*inv[k-2])%mod;
            f=(f*inv[len-k+1])%mod;
            ll id=pos[a[p]][i]+1;
            solve(id);
            if(dp[id].first+k>dp[p].first) dp[p]={dp[id].first+k,f*dp[id].second};
            else if(dp[id].first+k==dp[p].first && dp[p].first!=0) dp[p].second=(dp[p].second+f*dp[id].second)%mod;
    }
    return;
}

int main()
{

    fact[0]=inv[0]=1;
    for(ll i=1;i<=5000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv[i]=bigmod(fact[i],mod-2);
    }

    ll t;
    cin>>t;

    while(t--){
        cin>>n>>k;
        for(ll i=0;i<=n;i++){
            dp[i]={-1,-1};
            pos[i].clear();
        }
        dp[n+1]={0,1};
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            pos[a[i]].pb(i);
        }
        if(k==1){
            cout<<1<<endl;
            continue;
        }
        solve(1);
        cout<<dp[1].second<<endl;
    }

    return 0;
}