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

vector<pair<ll,ll>> v;
ll dp[200007][2],n;

ll solve(ll i,ll p){
    if(i==n-1) return 0;
    if(dp[i][p]!=-1) return dp[i][p];
    ll val;
    if(!p) val=v[i].first;
    else val=v[i].second;
    return dp[i][p]=min(solve(i+1,0)+val*v[i+1].second,solve(i+1,1)+val*v[i+1].first);
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        v.clear();
        ll s;
        cin>>n>>s;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            if(i==1) v.pb({a[i],0});
            else if(i<n){
                if(a[i]>=s) v.pb({s,a[i]-s});
                else v.pb({0,a[i]});
            }
            else v.pb({a[i],a[i]});
            dp[i-1][0]=dp[i-1][1]=-1;
        }
        ll ans=solve(0,0);
        cout<<ans<<"\n";
    }

    return 0;
}