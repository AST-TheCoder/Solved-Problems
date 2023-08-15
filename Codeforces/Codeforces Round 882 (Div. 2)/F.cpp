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

ll a[200007],node[200007];

void build(ll n,ll l,ll r){
    if(l==r){
        node[n]=a[l];
        return;
    }

    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node[n]=node[2*n]|node[2*n+1];
}

ll query(ll n,ll l,ll r,ll i,ll j){
    if(l>j || r<i) return 0;
    if(l>=i && r<=j) return node[n];
    return query(2*n,l,(l+r)/2,i,j)|query(2*n+1,(l+r)/2+1,r,i,j);
}

int main()
{

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n,q,v;
        scanf("%lli %lli",&n,&q);
        for(ll i=0;i<=8*n;i++) node[i]=0;
        ll x=0;
        for(ll i=1;i<=n;i++){
            scanf("%lli",&a[i]);
            x|=a[i];
        }
        v=-1;
        build(1,1,n);
        vector<pair<ll,ll>> temp;
        ll cnt=0;
        while(v!=x){
            ll l=1,r=n;
            ll ans=n*n,xx=x;
            while(l<=r){
                ll m=(l+r)/2;
                ll temp=0,val=-1;
                for(ll i=1;i<=n;i++){
                    if(i+m-1>n) break;
                    val=query(1,1,n,i,i+m-1);
                    temp++;
                    if(val>v) break;
                }
                if(val<=v && m>1){
                    val=query(1,1,n,1,m)|a[n];
                    if(val>v){
                        ans=m*n;
                        xx=val;
                        r=m-1;
                        continue;
                    }
                }
                if(val<=v || temp==0) l=m+1;
                else{
                    r=m-1;
                    xx=val;
                    ans=r*n+temp;
                }
            }
            temp.pb({xx,ans});
            v=xx;
        }

        while(q--){
            scanf("%lli",&v);
            if(v>=x){
                printf("-1\n");
                continue;
            }
            pair<ll,ll> pp={v,Max};
            ll id=upper_bound(all(temp),pp)-temp.begin();
            printf("%lli\n",temp[id].second);
        }
    }

    return 0;
}