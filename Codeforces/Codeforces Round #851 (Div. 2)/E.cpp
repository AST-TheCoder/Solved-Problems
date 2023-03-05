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

map<ll,ll> a;
vector<pair<ll,ll>> v;
ll dp[200007];

ll solve(ll i){
    if(i==v.size()) return 0;
    if(dp[i]!=-1) return 0;
    pair<ll,ll> temp={v[i].second,-1};
    ll id=upper_bound(all(v),temp)-v.begin();
    return dp[i]=max(solve(id)+v[i].second-v[i].first+1,solve(i+1));
}

int main()
{
    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;

    for(ll i=1,s=0;i<=n;i++){
        ll x;
        cin>>x;

        s+=x;
        if(a[s]){
            v.pb({a[s],i});
            cout<<a[s]<<" "<<i<<endl;
        }
        else a[s]=i;
    }

    sort(all(v));

    ll ans=solve(0);
    cout<<ans<<endl;

    return 0;
}