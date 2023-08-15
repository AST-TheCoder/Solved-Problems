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

ll mod=1000000007;
ll bigmod(ll n,ll p){
    if(!p) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

int main()
{

    ll k;
    cin>>k;

    ll ans=0,x=1,y=2;
    for(ll i=0;i<=k;i++){
        ll temp=(x*x)%mod;
        temp=(temp*y)%mod;
        ans=(ans+temp)%mod;
        y=(y*2)%mod;
        x=(x*(k-i))%mod;
        x=(x*bigmod(i+1,mod-2))%mod;
    }

    ans-=(k==0);

    cout<<ans<<endl;

    return 0;
}