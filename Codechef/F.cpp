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

pair<ll,ll> p[5007];

ll dp[5007][5007],n;
ll solve(ll i,ll j){
    if(i==n+1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=solve(i+1,j);
    if(p[i].first<p[j].first && p[i].second<p[j].second){
        dp[i][j]=max(dp[i][j],solve(i+1,i)+1);
    }
    return dp[i][j];
}

int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));

    for(ll i=1;i<=n;i++){
        cin>>p[i].first>>p[i].second;
        if(p[i].first<p[i].second) swap(p[i].first,p[i].second);
    }
    p[0].first=p[0].second=Max;
    sort(p+1,p+n+1,greater<pair<ll,ll>>());
    ll ans=solve(1,0);

    cout<<ans<<endl;

    return 0;
}