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

ll chk[500001],sod[500001],cnt[500001];

int main()
{

    for(ll i=1;i<=500000;i++){
        sod[i]=i-sod[i];
        for(ll j=i+i;j<=500000;j+=i) sod[j]+=sod[i];
    }

    ll n,q;
    scanf("%lli %lli",&n,&q);

    ll a[n+1],ans=0;
    for(ll i=1;i<=n;i++) scanf("%lli",&a[i]);

    while(q--){
        ll idx;
        scanf("%lli",&idx);
        ll val=a[idx];

        for(ll i=1;i*i<=val;i++){
            if(val%i==0){
                ll d=i;
                ll v=sod[d];
                if(!chk[idx]){
                    ans+=v*cnt[d];
                    cnt[d]++;
                }
                else{
                    cnt[d]--;
                    ans-=v*cnt[d];
                }
                if(i*i==val) continue;

                d=val/i;
                v=sod[d];
                if(!chk[idx]){
                    ans+=v*cnt[d];
                    cnt[d]++;
                }
                else{
                    cnt[d]--;
                    ans-=v*cnt[d];
                }
            }
        }
        chk[idx]=(chk[idx]==0);
        printf("%lli\n",ans);
    }

    return 0;
}