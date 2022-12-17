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

ll r=31625;
ll chk[31626];
vector<ll> p;

int main()
{

    p.pb(2);
    for(ll i=3;i<=r;i+=2){
        if(!chk[i]){
            p.pb(i);
            for(ll j=i+i;j<=r;j+=i) chk[j]=1;
        }
    }

    ll cnt[p.size()];
    
    ll t;
    scanf("%lli",&t);
    read:

    while(t--){
        memset(cnt,0,sizeof(cnt));
        ll n;
        scanf("%lli",&n);

        ll a[n];
        for(ll i=0;i<n;i++) scanf("%lli",&a[i]);

        for(ll i=0;i<n;i++){
            for(ll j=0;j<p.size() && p[j]<=a[i];j++){
                if(a[i]%p[j]==0){
                    cnt[j]++;
                    if(cnt[j]>1){
                        printf("YES\n");
                        goto read;
                    }
                    while(a[i]%p[j]==0) a[i]/=p[j];
                }
            }
        }

        sort(a,a+n);
        for(ll i=1;i<n;i++){
            if(a[i]==a[i-1] && a[i]!=1){
                printf("YES\n");
                goto read;
            }
        }

        printf("NO\n");
    }

    return 0;
}