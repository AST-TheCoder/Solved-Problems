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

ll mod=998244353,cnt[1000001],fact[5001],inv[5001],ret,dp[5001][5001];
bool chk[1000001];
vector<ll> pr;

ll bigmod(ll n,ll p){
    if(!p) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

ll solve(ll i,ll p){
    if(p==0) return ret;
    if(i==pr.size()) return 0;
    if(dp[i][p]!=-1) return dp[i][p];
    dp[i][p]=solve(i+1,p);
    ll x=solve(i+1,p-1);
    x=(x*fact[cnt[pr[i]]])%mod;
    x=(x*inv[cnt[pr[i]]+1])%mod;
    return dp[i][p]=(dp[i][p]+x)%mod;
}

int main()
{

    chk[1]=1;
    for(ll i=2;i<=1000000;i++){
        if(!chk[i]){
            for(ll j=2*i;j<=1000000;j+=i){
                chk[j]=1;
            }
        }
    }

    fact[0]=1;
    inv[0]=bigmod(fact[0],mod-2);
    for(ll i=1;i<=5000;i++){
        fact[i]=(i*fact[i-1])%mod;
        inv[i]=bigmod(fact[i],mod-2);
    }

    memset(dp,-1,sizeof(dp));

    ll n,sum=0;
    cin>>n;

    for(ll i=1;i<=2*n;i++){
        ll x;
        cin>>x;
        if(!chk[x]){
            pr.pb(x);
            chk[x]=1;
        }
        else{
            cnt[x]++;
            sum++;
        }
    }

    ret=fact[n];
    for(ll i=1;i<=1000000;i++){
        ret=(ret*inv[cnt[i]])%mod;
        //if(cnt[i]) cout<<i<<" "<<cnt[i]<<endl;
    }

    //for(ll i=0;i<pr.size();i++) cout<<pr[i]<<" ";cout<<endl;
    //cout<<sum<<" "<<ret<<endl;

    if(sum>n){
        cout<<0<<endl;
        return 0;
    }

    ll ans=solve(0,n-sum);
    cout<<ans<<endl;

    return 0;
}