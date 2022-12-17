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

ll dp[101],n;
ll mod=998244353;
ll a[101][101],x[101],y[101];

ll solve(ll i){
    if(i>n) return 1;

    if(dp[i]!=-1) return dp[i];

    dp[i]=0;
    for(ll j=i;j<=n;j++){
        ll ok=0;
        for(ll k=i;k<=j;k++){
            if(x[k]>j || y[k]<=j) ok=1;
        }
        if(!ok){
            dp[i]=(dp[i]+solve(j+1))%mod;
        }
    }
    
    return dp[i];
}

int main()
{

    cin>>n;
    memset(dp,-1,sizeof(dp));

    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]==1) x[i]=j;
        }
        y[i]=n+1;
        for(ll j=n;j>=i;j--){
            if(a[i][j]==2) y[i]=j;
        }
    }

    ll ans=(2*solve(1))%mod;
    cout<<ans<<endl;

    return 0;
}