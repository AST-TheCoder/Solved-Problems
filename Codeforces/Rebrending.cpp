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

ll idx[300001],node[1000001],nxt_s[300001],nxt_b[300001],seg_tree[1000001],temp[300001];

void build(ll n,ll l,ll r){
    if(l==r){
        node[n]=idx[l];
        seg_tree[n]=Max;
        return;
    }
    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node[n]=min(node[2*n],node[2*n+1]);
    seg_tree[n]=Max;
}

ll query (ll n,ll l,ll r,ll i,ll j){
    //cout<<l<<" "<<r<<" "<<i<<" "<<j<<endl;
    if(j<i) return 0;
    if(i>r || j<l) return Max;
    if(i<=l && r<=j){
        return node[n];
    }
    return min(query(2*n,l,(l+r)/2,i,j),query(2*n+1,(l+r)/2+1,r,i,j));
}

void upd(ll n,ll l,ll r,ll i,ll val){
    if(i<l || i>r) return;
    if(l==r){
        seg_tree[n]=val;
        temp[i]=val;
        return;
    }
    upd(2*n,l,(l+r)/2,i,val);
    upd(2*n+1,(l+r)/2+1,r,i,val);
    seg_tree[n]=min(seg_tree[2*n],seg_tree[2*n+1]);
}

ll find_ans(ll n,ll l,ll r,ll i,ll j){
    if(i>r || j<l) return Max;
    if(i<=l && r<=j){
        return seg_tree[n];
    }
    return min(find_ans(2*n,l,(l+r)/2,i,j),find_ans(2*n+1,(l+r)/2+1,r,i,j));
}

int main()
{

    ll n,q;
    scanf("%lli %lli",&n,&q);

    ll a[n+1];
    for(ll i=1;i<=n;i++){
        scanf("%lli",&a[i]);
        idx[a[i]]=i;
        temp[i]=Max;
    }
    build(1,1,n);

    deque<ll> dq;
    for(ll i=n;i>=1;i--){
        while(!dq.empty() && dq.back()<a[i]) dq.pop_back();
        if(!dq.empty()) nxt_b[i]=dq.back();
        else nxt_b[i]=-1;
        dq.push_back(a[i]);
    }
    while(!dq.empty()) dq.pop_back();

    for(ll i=n;i>=1;i--){
        while(!dq.empty() && dq.back()>a[i]) dq.pop_back();
        if(!dq.empty()) nxt_s[i]=dq.back();
        else nxt_s[i]=-1;
        dq.push_back(a[i]);
    }

    vector<pair<ll,ll>> queries[n+1];
    for(ll i=1;i<=q;i++){
        ll l,r;
        scanf("%lli %lli",&l,&r);
        queries[l].pb({r,i});
    }

    ll ans[q+1];
    for(ll i=n-1;i>=1;i--){
        if(nxt_b[i]!=-1){
            ll l=i,r=idx[nxt_b[i]];
            while(1){
                ll d=a[r]-a[l];
                ll val=min(temp[r],d);
                upd(1,1,n,r,val);
                ll id=query(1,1,n,a[l]+1,(a[l]+a[r])/2);
                //cout<<l<<" "<<r<<" "<<id<<" "<<a[l]+1<<" "<<(a[l]+a[r]-1)/2<<endl;
                if(id<=r || id==Max) break;
                r=id;
            }    
        }
        if(nxt_s[i]!=-1){
            ll l=i,r=idx[nxt_s[i]];
            while(1){
                ll d=a[l]-a[r];
                ll val=min(temp[r],d);
                upd(1,1,n,r,val);
                ll id=query(1,1,n,(a[l]+a[r])/2,a[l]-1);
                //cout<<l<<" "<<r<<" "<<id<<endl;
                if(id<=r || id==Max) break;
                r=id;
            }
        }
        for(ll j=0;j<queries[i].size();j++){
            ll val=find_ans(1,1,n,i,queries[i][j].first);
            ans[queries[i][j].second]=val;
        }
    }

    for(ll i=1;i<=q;i++){
        printf("%lli\n",ans[i]);
    }

    return 0;
}
