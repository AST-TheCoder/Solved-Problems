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

pair<ll,ll> dp[101][101];
ll a[101];

pair<ll,ll> solve(ll l,ll r){
    if(l>r) return {0,0};
    if(l==r) return {a[l],0};
    if(dp[l][r].first!=-Max) return dp[l][r];
    ll sum=0;
    for(ll i=l;i<=r;i++) sum+=a[i];
    for(ll i=l,s=0;i<=r;i++){
        s+=a[i];
        pair<ll,ll> x=solve(i+1,r);
        pair<ll,ll> y=solve(l,i-1);

        if(x.second+s>=dp[l][r].first) dp[l][r]={s+x.second,x.first};
        if(y.second+sum>=dp[l][r].first) dp[l][r]={sum+y.second,y.first};
        sum-=a[i];
    }
    //cout<<l<<" "<<r<<" "<<dp[l][r].first<<" "<<dp[l][r].second<<endl;
    return dp[l][r];
}

int main()
{

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++) dp[i][j]={-Max,-Max};
        }

        for(ll i=1;i<=n;i++) cin>>a[i];

        pair<ll,ll> ans=solve(1,n);
        //cout<<ans.first<<" "<<ans.second<<endl;
        cout<<"Case "<<++ii<<": "<<ans.first-ans.second<<endl;
    }

    return 0;
}