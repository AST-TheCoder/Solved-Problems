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

pair<ll,ll> a[2001];
ll dp[2001],id[2001],n;

ll solve(ll pos){
    if(pos>=n) return 0;
    if(dp[pos]!=-1) return dp[pos];
    dp[pos]=solve(pos+1)+1;
    for(ll i=pos+1;i<=id[pos];i++){
        ll temp=max(id[i],id[pos])-pos-1;
        dp[pos]=min(dp[pos],solve(max(id[i],id[pos])+1)+temp);
    }
    return dp[pos];
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        cin>>n;
        for(ll i=0;i<n;i++) cin>>a[i].first>>a[i].second;
        memset(dp,-1,sizeof(dp));

        sort(a,a+n);
        for(ll i=0;i<n;i++){
            id[i]=i;
            for(ll j=0;j<n;j++){
                if(a[i].second>=a[j].first) id[i]=j;
                else break;
            }
        }

        ll ans=solve(0);
        cout<<ans<<endl;
    }

    return 0;
}