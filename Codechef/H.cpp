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

ll spf[15000001],cnt[15000001];

int main()
{

    for(ll i=2;i<15000001;i++){
        if(spf[i]) continue;
        for(ll j=i;j<15000001;j+=i) spf[j]=i;
    }

    ll n,g=0;
    scanf("%lli",&n);
    ll a[n];
    for(ll i=0;i<n;i++){
        scanf("%lli",&a[i]);
        g=__gcd(a[i],g);
    }
    for(ll i=0;i<n;i++) a[i]/=g;

    for(ll i=0;i<n;i++){
        ll v=a[i];
        set<ll> temp;
        while(v!=1){
            temp.insert(spf[v]);
            v/=spf[v];
        }
        for(auto x: temp) cnt[x]++;
    }

    ll ans=n;
    for(ll i=2;i<15000001;i++) ans=min(ans,n-cnt[i]);
    if(ans==n) ans=-1;
    printf("%lli\n",ans);

    return 0;
}