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

ll node[1000000],prop[1000000],a[100007],id[1000000],ans[100007];

void build(ll n,ll l,ll r){

    if(l==r){
        node[n]=a[l];
        id[n]=l;
        return;
    }

    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);

    if(node[2*n]<node[2*n+1]){
        node[n]=node[2*n];
        id[n]=id[2*n];
    }
    else{
        node[n]=node[2*n+1];
        id[n]=id[2*n+1];
    }

}

void propagate(ll n,ll l,ll r){
    if(l==r){
        prop[n]=0;
        return;
    }
    node[2*n]+=prop[n];
    node[2*n+1]+=prop[n];

    if(node[2*n]<node[2*n+1]){
        node[n]=node[2*n];
        id[n]=id[2*n];
    }
    else{
        node[n]=node[2*n+1];
        id[n]=id[2*n+1];
    }

    prop[2*n]+=prop[n];
    prop[2*n+1]+=prop[n];

    prop[n]=0;
}

void update(ll n,ll l,ll r,ll i,ll j,ll val){
    //cout<<n<<" "<<l<<" "<<r<<" "<<i<<" "<<j<<endl;
    propagate(n,l,r);
    if(r<i || l>j) return;
    if(i<=l && r<=j){
        node[n]+=val;
        prop[n]+=val;
        return;
    }
    update(2*n,l,(l+r)/2,i,j,val);
    update(2*n+1,(l+r)/2+1,r,i,j,val);

    if(node[2*n]<node[2*n+1]){
        node[n]=node[2*n];
        id[n]=id[2*n];
    }
    else{
        node[n]=node[2*n+1];
        id[n]=id[2*n+1];
    }
}

int main()
{

    ll t,ii=0;
    scanf("%lli",&t);
    while(t--){
        ll n;
        scanf("%lli",&n);
        
        for(ll i=0;i<=8*n;i++){
            node[i]=Max;
            prop[i]=0;
            id[i]=0;
        }

        for(ll i=1;i<=n;i++) scanf("%lli",&a[i]);

        build(1,1,n);

        for(ll i=1;i<=n;i++){
            ll idx=id[1];
            //cout<<idx<<endl;
            ans[idx]=n-i+1;
            update(1,1,n,idx,idx,Max);
            update(1,1,n,idx,n,-1);
        }
        printf("Case %lli: %lli\n",++ii,ans[1]);
    }

    return 0;
}