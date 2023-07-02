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

ll n,m,p,q,fact[51],mod=1000000007,inv[51];
ll bigmod(ll val,ll pwr){
    if(!pwr) return 1;
    if(pwr%2) return (val*bigmod(val,pwr-1))%mod;
    ll temp=bigmod(val,pwr/2);
    return (temp*temp)%mod;
}
pair<ll,ll> dp[51][51][2];

pair<ll,ll> solve(ll x,ll y,ll side){
    if(!x && !y) return {0,1};
    if(dp[x][y][side].first!=-1) return dp[x][y][side];
    dp[x][y][side]={Max,0};

    if(!side){
        for(ll i=0;i<=x;i++){
            for(ll j=0;j<=y;j++){
                ll w=50*i+100*j;
                if(w>m) break;
                if(!w) continue;
                pair<ll,ll> temp=solve(x-i,y-j,1);
                temp.first++;
                ll f1=(fact[x]*inv[i])%mod;
                f1=(f1*inv[x-i])%mod;
                ll f2=(fact[y]*inv[j])%mod;
                f2=(f2*inv[y-j])%mod;
                temp.second=(temp.second*f1)%mod;
                temp.second=(temp.second*f2)%mod;
                if(dp[x][y][side].first==temp.first) dp[x][y][side].second=(dp[x][y][side].second+temp.second)%mod;
                else if(dp[x][y][side].first>temp.first) dp[x][y][side]=temp;
            }
        }
    }
    else{
        for(ll i=0;i<=p-x;i++){
            for(ll j=0;j<=q-y;j++){
                ll w=50*i+100*j;
                if(w>m) break;
                if(!w) continue;
                pair<ll,ll> temp=solve(x+i,y+j,0);
                temp.first++;
                ll f1=(fact[p-x]*inv[i])%mod;
                f1=(f1*inv[p-x-i])%mod;
                ll f2=(fact[q-y]*inv[j])%mod;
                f2=(f2*inv[q-y-j])%mod;
                temp.second=(temp.second*f1)%mod;
                temp.second=(temp.second*f2)%mod;
                if(dp[x][y][side].first==temp.first) dp[x][y][side].second=(dp[x][y][side].second+temp.second)%mod;
                else if(dp[x][y][side].first>temp.first) dp[x][y][side]=temp;
            }
        }
    }
    return dp[x][y][side];
}

int main()
{
    fact[0]=1;
    inv[0]=1;
    for(ll i=1;i<=50;i++){
        fact[i]=(i*fact[i-1])%mod;
        inv[i]=bigmod(fact[i],mod-2);
    }
    for(ll i=0;i<=50;i++){
        for(ll j=0;j<=50;j++){
            for(ll k=0;k<2;k++)
                dp[i][j][k]={-1,-1};
        }
    }
    cin>>n>>m;
    for(ll i=0;i<n;i++){
        ll temp;
        cin>>temp;
        if(temp==50) p++;
        else q++;
    }

    pair<ll,ll> ans=solve(p,q,0);
    if(ans.first==Max) ans.first=-1;
    cout<<ans.first<<endl<<ans.second<<endl;

    return 0;
}