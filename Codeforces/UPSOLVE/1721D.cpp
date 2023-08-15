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

ll a[100001],b[100001],x[100001],y[100001],n;

void rearrange(ll k){
    if(k<0) return;
    for(ll id=1;id<=n;){
        ll p=id,q=id;
        while(!y[q]) q++;
        id=q+1;
        for(ll i=p,j=p;i<=q;i++){
            if(!(a[i]&(1LL<<k))){
                swap(a[i],a[j]);
                j++;
            }
        }
        for(ll i=p,j=p;i<=q;i++){
            if(b[i]&(1LL<<k)){
                swap(b[i],b[j]);
                j++;
            }
        }
    }

    for(ll i=1;i<=n;i++){
        if((a[i]&(1LL<<k))==(b[i]&(1LL<<k))){
            rearrange(k-1);
            return;
        }
    }
    
    for(ll i=1;i<=n;){
        ll p=i,q=i;
        while(!y[q]) q++;
        i=q+1;
        if((a[p]&(1LL<<k))==(a[q]&(1LL<<k))) continue;
        for(ll j=p;j<=q;j++){
            if(a[j]&(1LL<<k)){
                x[j]=y[j-1]=1;
                break;
            }
        }
    }
    rearrange(k-1);
}

int main()
{

    ll t;
    scanf("%lli",&t);

    while(t--){
        scanf("%lli",&n);
        for(ll i=1;i<=n;i++) scanf("%lli",&a[i]);
        for(ll i=1;i<=n;i++) scanf("%lli",&b[i]);
        for(ll i=1;i<=n;i++) x[i]=y[i]=0;
        sort(a+1,a+n+1);
        x[1]=y[n]=1;
        rearrange(30);
        ll ans=a[1]^b[1];
        for(ll i=2;i<=n;i++) ans&=(a[i]^b[i]);
        printf("%lli\n",ans);
    }

    return 0;
}