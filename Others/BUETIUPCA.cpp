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

ll c[1000007],p[1000007],a[1000007],v[4000007],prop[4000007],x[4000007];

void build_p(ll n,ll l,ll r){
    if(l==r){
        v[n]=p[l];
        return;
    }
    build_p(2*n,l,(l+r)/2);
    build_p(2*n+1,(l+r)/2+1,r);
    v[n]=min(v[2*n],v[2*n+1]);
}

void relax(ll n,ll l,ll r){
    if(l==r){
        prop[n]=0;
        return;
    }
    v[2*n]+=prop[n];
    v[2*n+1]+=prop[n];
    prop[2*n]+=prop[n];
    prop[2*n+1]=prop[n];
    prop[n]=0;
}

ll query_p(ll n,ll l,ll r){
    relax(n,l,r);
    if(v[n]) return r;
    if(l==r) return l;
    if(v[2*n]==v[n]) return query_p(2*n,l,(l+r)/2);
    else return query_p(2*n+1,(l+r)/2+1,r);
}

void update_p(ll n,ll l,ll r,ll i,ll j,ll val){
    relax(n,l,r);
    if(j<l || i>r) return;
    if(i<=l && j>=r){
        v[n]+=val;
        prop[n]=val;
        return;
    }
    update_p(2*n,l,(l+r)/2,i,j,val);
    update_p(2*n+1,(l+r)/2+1,r,i,j,val);
    v[n]=min(v[2*n],v[2*n+1]);
}

void build_c(ll n,ll l,ll r){
    if(l==r){
        x[n]=l;
        return;
    }
    build_c(2*n,l,(l+r)/2);
    build_c(2*n+1,(l+r)/2+1,r);
    if(c[x[2*n]]>=c[x[2*n+1]]) x[n]=x[2*n];
    else x[n]=x[2*n+1];
}

ll query_c(ll n,ll l,ll r,ll i,ll j){
    if(j<l || i>r) return 0;
    if(i<=l && j>=r) return x[n];
    ll lid=query_c(2*n,l,(l+r)/2,i,j);
    ll rid=query_c(2*n+1,(l+r)/2+1,r,i,j);
    if(c[lid]>=c[rid]) return lid;
    else return rid;
}

void update_c(ll n,ll l,ll r,ll i){
    if(i<l || i>r) return;
    if(l==r){
        c[l]=0;
        return;
    }
    update_c(2*n,l,(l+r)/2,i);
    update_c(2*n+1,(l+r)/2+1,r,i);
    if(c[x[2*n]]>=c[x[2*n+1]]) x[n]=x[2*n];
    else x[n]=x[2*n+1];
}

int main()
{

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;

        for(ll i=0;i<=4*n;i++){
            if(i<=n) a[i]=c[i]=p[i]=0;
            v[i]=prop[i]=x[i]=0;
        }

        string s;
        cin>>s;
        s="#"+s;

        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        for(ll i=1;i<=n;i++){
            if(s[i]=='P') p[i]=p[i-1]+1;
            else{
                p[i]=p[i-1]-1;
                c[i]=a[i];
            }
        }

        build_p(1,1,n);
        build_c(1,1,n);

        ll cnt=count(all(s),'C'),ans=0;
        for(ll i=1;i<=n && cnt;i++){
            if(s[i]=='C') continue;
            cnt--;

            ll idx=query_p(1,1,n);
            idx=query_c(1,1,n,i,idx);
            ans+=a[i]*a[idx];
            update_p(1,1,n,i,i,Max);
            update_p(1,1,n,idx,idx,Max);
            update_p(1,1,n,i,idx,-1);
            update_c(1,1,n,idx);
            cout<<i<<" "<<idx<<endl;
            for(ll j=1;j<=n;j++) cout<<c[j]<<" ";cout<<endl;
        }
        cout<<ans<<endl;
    }

    return 0;
}