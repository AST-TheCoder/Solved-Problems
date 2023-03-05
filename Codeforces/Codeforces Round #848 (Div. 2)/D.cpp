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

ll mod=998244353;

ll bigmod(ll n,ll p){
    if(p==0) return 1;
    if(p%2) return (n*bigmod(n,p-1))%mod;
    ll x=bigmod(n,p/2);
    return (x*x)%mod;
}

ll solve(ll n,ll p,ll q){
    if(q==0) return 0;
    ll temp=solve(n,p+1,q-1);
    temp=(temp*q+q+2*p)%mod;
    temp=(temp*bigmod(n-p,mod-2))%mod;
    return temp;
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        string a,b;
        cin>>a>>b;

        ll p=0,q=0;
        for(ll i=0;i<n;i++){
            if(a[i]==b[i]) p++;
            else q++;
        }

        ll ans=solve(n,p,q);
        cout<<ans<<endl;
    }

    return 0;
}