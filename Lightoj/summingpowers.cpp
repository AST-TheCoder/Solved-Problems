#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll unsigned long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

ll mod=(1LL<<32);
vector<ll> co_eff[51],ans;

void solve(ll n,ll k){
    if(n==1){
        for(ll i=0;i<=k;i++) ans.pb(1);
        return;
    }
    vector<ll> temp;
    if(n%2){
        solve(n-1,k);
        temp.pb(1);
        for(ll i=1;i<=k;i++) temp.pb((temp[i-1]*n)%mod);
        for(ll i=0;i<=k;i++) ans[i]=(ans[i]+temp[i])%mod;
        return;
    }
    solve(n/2,k);
    temp.pb(1);
    for(ll i=1;i<=k;i++) temp.pb((temp[i-1]*(n/2))%mod);
    for(int i=k;i>=0;i--){
        ll val=0;
        for(ll j=0;j<=i;j++){
            ll v=(ans[j]*co_eff[i][j])%mod;
            v=(v*temp[i-j])%mod;
            val=(val+v)%mod;
        }
        ans[i]=(ans[i]+val)%mod;
    }
}

int main()
{

    co_eff[0].pb(1);
    for(ll i=1;i<=50;i++){
        for(ll j=0;j<=i;j++){
            if(!j || j==i){
                co_eff[i].pb(1);
                continue;
            }
            co_eff[i].pb((co_eff[i-1][j]+co_eff[i-1][j-1])%mod);
        }
    }

    int t,ii=0;
    cin>>t;

    while(t--){
        ans.clear();
        ll n,k;
        cin>>n>>k;
        solve(n,k);
        cout<<"Case "<<++ii<<": "<<ans[k]<<endl;
    }

    return 0;
}