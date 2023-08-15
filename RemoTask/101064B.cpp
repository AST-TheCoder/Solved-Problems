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

ll dp[61][61][61][61][2],mod=1000000007;

ll solve(ll a,ll b,ll c,ll d,ll x){
    if(!a && !b && !c && !d) return x;
    if(dp[a][b][c][d][x]!=-1) return dp[a][b][c][d][x];
    dp[a][b][c][d][x]=0;
    for(ll i=1;i<=a;i++)dp[a][b][c][d][x]=(dp[a][b][c][d][x]+solve(i-1,a+b-i,c,d,x))%mod;
    for(ll i=1;i<=b;i++)dp[a][b][c][d][x]=(dp[a][b][c][d][x]+solve(a,i-1,b+c-i,d,x))%mod;
    for(ll i=1;i<=c;i++)dp[a][b][c][d][x]=(dp[a][b][c][d][x]+solve(a,b,i-1,c+d-i,1))%mod;
    if(d) dp[a][b][c][d][x]=(dp[a][b][c][d][x]+solve(a,b,c,d-1,1))%mod;
    return dp[a][b][c][d][x];
}

int main()
{

    memset(dp,-1,sizeof(dp));
    ll n;
    cin>>n;
    ll ans=1;
    for(ll i=1;i<=n;i++) ans=(ans*i)%mod;

    ans=(ans-solve(n,0,0,0,0)+mod)%mod;
    cout<<ans<<endl;

    return 0;
}