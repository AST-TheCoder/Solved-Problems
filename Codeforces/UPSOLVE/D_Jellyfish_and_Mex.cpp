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

ll dp[5001],c[5001];
ll solve(ll mex){
    if(!mex) return 0;
    if(dp[mex]!=-1) return dp[mex];

    dp[mex]=Max;
    for(ll i=0;i<mex;i++){
        ll temp=(c[i]-1)*mex+i+solve(i);
        dp[mex]=min(dp[mex],temp);
    }
    return dp[mex];
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll a[n];
        memset(c,0,sizeof(c));
        memset(dp,-1,sizeof(dp));
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<=n) c[a[i]]++;
        }

        ll mex=0;
        while(c[mex]) mex++;

        ll ans=solve(mex);
        cout<<ans<<endl;
    }

    return 0;
}