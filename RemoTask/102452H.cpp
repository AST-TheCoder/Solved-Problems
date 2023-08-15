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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

multiset<ll> s[2000007];

void update(ll n,ll l,ll r,ll id,ll val){
    if(l>id || r<id) return;
    s[n].insert(val);
    if(l==r) return;
    update(2*n,l,(l+r)/2,id,val);
    update(2*n+1,(l+r)/2+1,r,id,val);
}

ll query(ll n,ll l,ll r,ll i,ll j,ll val){
    if(l>j || r<i) return Max;
    if(i<=l && j>=r){
        set<ll>::iterator it=s[n].upper_bound(val);
        ll ret=Max;
        if(it!=s[n].end()){
            ll v=*it;
            if(v) ret=min(ret,abs(val-v));
        }
        if(it!=s[n].begin()){
            it--;
            ll v=*it;
            if(v) ret=min(ret,abs(val-v));
        }
        return ret;
    }
    return min(query(2*n,l,(l+r)/2,i,j,val),query(2*n+1,(l+r)/2+1,r,i,j,val));
}

int main()
{

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n,m;
        scanf("%lli %lli",&n,&m);
        for(ll i=0;i<=4*n;i++) s[i].clear();

        while(m--){
            ll tp;
            scanf("%lli",&tp);
            if(!tp){
                ll id,val;
                scanf("%lli %lli",&id,&val);
                update(1,1,n,id,val);
            }
            else{
                ll l,r,val;
                scanf("%lli %lli %lli",&l,&r,&val);
                ll ans=query(1,1,n,l,r,val);
                if(ans==Max) ans=-1;
                printf("%lli\n",ans);
            }
        }
    }

    return 0;
}