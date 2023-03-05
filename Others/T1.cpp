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

ll phi[20000001];
ll solve(ll n){
    if(n<=20000000) return phi[n];
    ll ans=(n*(n+1))/2;
    ll l=2;
    while(l<=n){
        ll temp=n/l;
        ll r=n/temp;
        ans-=solve(temp)*(r-l+1);
        l=r+1;
    }
    return ans;
}

int main()
{

    for(ll i=1;i<=20000000;i++) phi[i]=i;
    for(ll i=2;i<=20000000;i++){
        if(phi[i]==i){
            for(ll j=i;j<=20000000;j+=i) phi[j]-=phi[j]/i;
        }
        phi[i]+=phi[i-1];
    }
    
    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n,d;
        scanf("%lli %lli",&n,&d);
        n/=d;
        ll ans=solve(n);
        printf("%lli\n",ans);
    }

    return 0;
}