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

ll dp[5001][5001],n,k,a[5001],h[5001],c[5001];

ll solve(ll id,ll p){
    if(id>n) return 0;
    if(dp[id][p]!=-1) return dp[id][p];
    ll x=solve(id+1,id-1);
    if(a[p]==a[id]) x+=h[a[id]];
    else x+=c[a[id]];

    ll y=solve(id+1,p);
    if(a[id-1]==a[id]) y+=h[a[id]];
    else y+=c[a[id]];

    return dp[id][p]=min(x,y);
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        cin>>n>>k;

        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=n;j++) dp[i][j]=-1;
        }
        for(ll i=1;i<=n;i++) cin>>a[i];
        for(ll i=1;i<=k;i++) cin>>c[i];
        for(ll i=1;i<=k;i++) cin>>h[i];

        ll ans=solve(1,0);
        cout<<ans<<endl;
    }

    return 0;
}