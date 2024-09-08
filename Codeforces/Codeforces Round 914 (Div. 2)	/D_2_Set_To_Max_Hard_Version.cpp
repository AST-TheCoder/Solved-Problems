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

ll a[200007],b[200007],node1[1000007],node2[1000007];
vector<ll> idx[200007];

void build(ll n,ll l,ll r){
    if(l==r){
        node1[n]=a[l];
        node2[n]=b[l];
        return;
    }
    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node1[n]=max(node1[2*n],node1[2*n+1]);
    node2[n]=min(node2[2*n],node2[2*n+1]);
}

ll query1(ll n,ll l,ll r,ll i,ll j){
    if(j<l || r<i) return 0;
    if(l>=i && r<=j) return node1[n];
    return max(query1(2*n,l,(l+r)/2,i,j),query1(2*n+1,(l+r)/2+1,r,i,j));
}

ll query2(ll n,ll l,ll r,ll i,ll j){
    if(j<l || r<i) return Max;
    if(l>=i && r<=j) return node2[n];
    return min(query2(2*n,l,(l+r)/2,i,j),query2(2*n+1,(l+r)/2+1,r,i,j));
}

int main()
{

    ll t;
    cin>>t;

    read:
    while(t--){
        ll n;
        cin>>n;

        for(ll i=0;i<=4*n;i++){
            if(i<=n){
                idx[i].clear();
            }
            node1[i]=0;
            node2[i]=Max;
        }

        for(ll i=1;i<=n;i++){
            cin>>a[i];
            idx[a[i]].pb(i);
        }
        for(ll i=1;i<=n;i++){
            cin>>b[i];
        }
        build(1,1,n);
        
        for(ll i=1;i<=n;i++){
            if(a[i]>b[i]){
                cout<<"NO"<<endl;
                goto read;
            }
            if(a[i]==b[i]) continue;
            ll chk=0;
            
            ll id=upper_bound(all(idx[b[i]]),i)-idx[b[i]].begin();
            if(id<idx[b[i]].size()){
                ll j=idx[b[i]][id];
                //cout<<"chk"<<" "<<j<<endl;
                ll u=query1(1,1,n,i,j);
                ll v=query2(1,1,n,i,j);
                if(u==b[i] && v==b[i]) chk=1;
            }

            if(id){
                id--;
                ll j=idx[b[i]][id];
                //cout<<"chk"<<" "<<j<<endl;
                ll u=query1(1,1,n,j,i);
                ll v=query2(1,1,n,j,i);
                if(u==b[i] && v==b[i]) chk=1;
            }

            if(!chk){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }

    return 0;
}