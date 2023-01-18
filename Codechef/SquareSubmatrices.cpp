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

int main()
{

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n,x;
        scanf("%lli %lli",&n,&x);

        vector<ll> d;
        for(ll i=1;i*i<=x;i++){
            if(x%i==0){
                d.pb(i);
                if(i!=i/x) d.pb(i/x);
            }
        }

        ll a[n+1];
        a[0]=0;
        for(ll i=1;i<=n;i++){
            scanf("%lli",&a[i]);
            a[i]+=a[i-1];
        }

        ll ans=0;
        ll cnt[x+1];
        for(ll i=0;i<d.size();i++){
            if(d[i]>n) continue;
            ll len=d[i];
            memset(cnt,0,sizeof(cnt));
            for(ll l=0,r=len;r<=n;r++,l++){
                ll s=len*(a[r]-a[l]);
                if(s>x) continue;
                cnt[s]++;
            }
            for(ll l=0,r=len;r<=n;r++,l++){
                ll s=len*(a[r]-a[l]);
                if(s>x) continue;
                ans+=cnt[x-s];
            }
        }

        printf("%lli\n",ans);
    }

    return 0;
}