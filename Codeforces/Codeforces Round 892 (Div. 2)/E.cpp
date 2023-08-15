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

ll dp[3001][3001];

int main()
{

    ll t;
    scanf("%lli",&t);
    while(t--){
        ll n,k;
        scanf("%lli %lli",&n,&k);
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=k;j++) dp[i][j]=0;
        }

        ll a[n+1],b[n+1];
        for(ll i=1;i<=n;i++) scanf("%lli",a[i]);
        for(ll i=1;i<=n;i++) scanf("%lli",b[i]);

        ll ans=0;
        

        printf("%lli\n",ans);
    }

    return 0;
}