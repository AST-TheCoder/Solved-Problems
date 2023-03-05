#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max INT_MAX

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

vector<ll> idx[4000007],val[4000007];
ll avg[4000007],leaf_val[4000007];
void build(ll n){
    ll p=0,q=Max;
    for(ll i=0;i<val[n].size();i++){
        p=max(p,val[n][i]);
        q=min(q,val[n][i]);
    }

    if(p==q){
        leaf_val[n]=p;
        return;
    }
    ll mid=(p+q)/2;
    idx[n].pb(0);
    for(ll i=0;i<val[n].size();i++){
        if(val[n][i]<=mid){
            val[2*n].pb(val[n][i]);
            idx[n].pb(idx[n][i]+1);
        }
        else{
            val[2*n+1].pb(val[n][i]);
            idx[n].pb(idx[n][i]);
        }
    }
    avg[n]=mid;
    build(2*n);
    build(2*n+1);
}

ll query(ll n,ll l,ll r,ll v,ll dis){
    if(r<0) return v+dis;
    if(!avg[n]){
        ll num=r-l;
        ll d=leaf_val[n]-num-dis;
        if(d<v) dis+=num;
        return v+dis;
    }
    
    ll num=idx[n][r+1]-idx[n][l+1];
    ll d=avg[n]-num-dis;
    if(d>=v) return query(2*n,idx[n][l+1]-1,idx[n][r+1]-1,v,dis);
    else return query(2*n+1,l-idx[n][l+1],r-idx[n][r+1],v,dis+num);
}


int main()
{
    ll n;
    scanf("%d",&n);

    for(ll i=1;i<=n;i++){
        ll x;
        scanf("%d",&x);
        val[1].pb(x);
    }

    build(1);
    ll q;
    scanf("%d",&q);

    while(q--){
        ll p,q,k;
        scanf("%d %d %d",&p,&q,&k);
        if(p>q) swap(p,q);
        p--,q--;
        ll ans=query(1,p-1,q,k,0);
        
        printf("%d\n",ans);
    }

    return 0;
}