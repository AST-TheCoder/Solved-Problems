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

bool chk[500001];
vector<ll> pc[500001];
ll n,dp[500001],mod=1000000007;

ll bigmod(ll v,ll p){
    if(!p) return 1;
    if(p%2) return (v*bigmod(v,p-1))%mod;
    ll temp=bigmod(v,p/2);
    return (temp*temp)%mod;
}

int main()
{
    freopen("out/v.in","r",stdin);
    freopen("out/v.out","w",stdout);
    cin>>n;

    for(ll i=1;i<=n;i++) pc[i].pb(1);
    
    for(ll i=2;i<=n;i++){
        if(chk[i]) continue;
        for(ll j=i;j<=n;j+=i){
            chk[j]=1;
            ll temp=pc[j].size();
            for(ll k=0;k<temp;k++){
                pc[j].pb(-i*pc[j][k]);
            }
        }
    }
    
    for(ll i=1;i<=n;i++){
        if(i!=1){
            dp[i]=(dp[i]+n)%mod;
            dp[i]=(dp[i]*bigmod(n-n/i,mod-2))%mod;
        }
        for(ll j=2*i;j<=n;j+=i){
            ll d=n/i;
            ll cp=0;
            for(ll k=0;k<pc[j/i].size();k++){
                cp+=d/pc[j/i][k];
            }
            //cout<<j<<" "<<n<<" "<<i<<" "<<cp<<endl;
            dp[j]=(dp[j]+cp*dp[i])%mod;
        }
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return 0;
}