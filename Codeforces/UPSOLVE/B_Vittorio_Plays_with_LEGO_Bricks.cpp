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

ll n,h;
ll dp[301][301],b[301][301],x[301];

ll solve(ll l,ll r){
    if(l==r){
        b[l][r]=h;
        return dp[l][r]=0;
    }
    if(dp[l][r]!=-1) return dp[l][r];
    dp[l][r]=Max;
    b[l][r]=floor((double)(2*h+x[l]-x[r])/2.0);
    for(ll i=l;i<r;i++){
        ll temp=solve(l,i)+solve(i+1,r)+max(0LL,b[l][i])+max(0LL,b[i+1][r])-2*max(0LL,b[l][r])-(b[l][r]>=0);
        dp[l][r]=min(dp[l][r],temp);
    }
    return dp[l][r];
}

int main()
{

    cin>>n>>h;
    memset(dp,-1,sizeof(dp));
    for(ll i=1;i<=n;i++) cin>>x[i];

    ll ans=solve(1,n)+max(0LL,b[1][n]);
    cout<<ans<<endl;

    return 0;
}