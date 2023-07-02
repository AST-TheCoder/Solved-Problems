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

    ll n,k,a;
    cin>>n>>k>>a;

    ll dp[k+2],idx=k+1;
    memset(dp,0,sizeof(dp));

    vector<pair<ll,ll>> v[k+1];
    for(ll i=0;i<n;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        v[x].pb({y,w});
    }

    for(ll i=0;i<=k;i++){
        sort(all(v[i]));
        for(ll j=1;j<v[i].size();j++){
            v[i][j].second+=v[i][j-1].second;
        }
    }
    
    for(ll x=0;x<=k;x++){
        for(ll y=0;y<=min(k-x,idx-1);y++){
            pair<ll,ll> temp={y,-1};
            ll id=lower_bound(all(v[x]),temp)-v[x].begin();
            dp[y]=0;
            if(id<v[x].size()) dp[y]=a*(k-x-y);
            dp[y]+=dp[y+1];
            if(!id) continue;
            id--;
            dp[y]+=v[x][id].second;
        }
        idx=min(idx,k-x);
        for(ll y=min(k-x-1,idx-2);y>=0;y--){
            if(dp[y]<dp[y+1]) idx=y;
            dp[y]=min(dp[y],dp[y+1]);
        }
        for(ll y=0;y<=min(k-x,idx-1);y++) cout<<x<<" "<<y<<" "<<dp[y]<<endl;
    }

    cout<<dp[0]<<endl;

    return 0;
}