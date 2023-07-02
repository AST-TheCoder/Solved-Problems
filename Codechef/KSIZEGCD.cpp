#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

ll a[100007],node[400007];

void build(ll n,ll l,ll r){
    if(l==r){
        node[n]=a[l];
        return;
    }
    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node[n]=__gcd(node[2*n],node[2*n+1]);
}

ll query(ll n,ll l,ll r,ll i,ll val){
    if(r<=i || node[n]%val==0) return -1;
    if(l==r) return l;
    ll id=query(2*n,l,(l+r)/2,i,val);
    if(id!=-1) return id;
    return query(2*n+1,(l+r)/2+1,r,i,val);
}

int main()
{

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n;
        scanf("%lli",&n);

        for(ll i=0;i<=4*n;i++) node[i]=0;

        ll ans[n+1];
        for(ll i=1;i<=n;i++){
            ans[i]=1;
            scanf("%lli",&a[i]);
        }
        build(1,1,n);
        
        for(ll i=n;i>=1;i--){
            ll g=0;
            for(ll j=i;j<=n && g!=1;){
                g=__gcd(g,a[j]);
                if(g==1) break;
                j=query(1,1,n,j,g);
                if(j==-1) j=n+1;
                ans[j-i]=max(ans[j-i],g);
            }
        }

        for(ll i=n-1;i>=1;i--){
            ans[i]=max(ans[i+1],ans[i]);
        }
        for(ll i=1;i<=n;i++) printf("%lli ",ans[i]);
        printf("\n");
    }

    return 0;
}