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

ll a[200007],node[800007];

void build(ll n,ll l,ll r){
    if(l==r){
        node[n]=a[l];
        return;
    }
    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node[n]=node[2*n]+node[2*n+1];
}

void upd(ll n,ll l,ll r,ll i,ll v){
    if(l>i || r<i) return;
    if(l==r){
        node[n]+=v;
        a[l]+=v;
        return;
    }
    upd(2*n,l,(l+r)/2,i,v);
    upd(2*n+1,(l+r)/2+1,r,i,v);
    node[n]=node[2*n]+node[2*n+1];
}

ll query(ll n,ll l,ll r,ll i,ll j){
    if(l>j || r<i) return 0;
    if(l>=i && r<=j) return node[n];
    return query(2*n,l,(l+r)/2,i,j)+query(2*n+1,(l+r)/2+1,r,i,j);
}

int main()
{

    ll n,m,q;
    cin>>n>>m>>q;

    string s;
    cin>>s;

    ll pos[n],p=0,tot=count(all(s),'1');
    memset(pos,-1,sizeof(pos));
    set<ll> x;
    for(ll i=0;i<n;i++) x.insert(i);

    for(ll i=0;i<m;i++){
        ll l,r;
        cin>>l>>r;
        l--,r--;
        set<ll>::iterator it=x.lower_bound(l);
        vector<ll> temp;
        for(;it!=x.end() && *it<=r;it++){
            pos[*it]=p;
            a[p]=s[*it]-'0';
            temp.pb(*it);
            p++;
        }
        for(ll j=0;j<temp.size();j++) x.erase(temp[j]);
    }

    build(1,0,p-1);
    while(q--){
        ll id;
        cin>>id;
        id--;
        if(s[id]=='1'){
            s[id]='0';
            tot--;
            if(pos[id]!=-1){
                upd(1,0,p-1,pos[id],-1);
            }
        }
        else{
            s[id]='1';
            tot++;
            if(pos[id]!=-1){
                upd(1,0,p-1,pos[id],1);
            }
        }

        ll ans=query(1,0,p-1,0,min(tot,p)-1);
        cout<<min(p,tot)-ans<<endl;
    }

    return 0;
}