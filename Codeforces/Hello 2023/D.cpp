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

ll b[200007],node[800007];

void build(ll n,ll l,ll r){
    if(l==r){
        node[n]=b[l];
        return;
    }
    build(2*n,l,(l+r)/2);
    build(2*n+1,(l+r)/2+1,r);
    node[n]=max(node[2*n],node[2*n+1]);
}

ll query(ll n,ll l,ll r,ll i,ll j){
    if(l>j || r<i) return 0;
    if(l>=i && r<=j) return node[n];

    ll x=query(2*n,l,(l+r)/2,i,j);
    ll y=query(2*n+1,(l+r)/2+1,r,i,j);
    return max(x,y);
}

int main()
{

    ll t;
    scanf("%lli",&t);

    read:
    while(t--){
        ll n;
        scanf("%lli",&n);

        for(ll i=0;i<=4*n;i++) node[i]=0;

        ll a[n+1];
        for(ll i=1;i<=n;i++) scanf("%lli",&a[i]);
        for(ll i=1;i<=n;i++) scanf("%lli",&b[i]);
        build(1,1,n);

        ll m;
        scanf("%lli",&m);
        ll c[m];
        for(ll i=0;i<m;i++) scanf("%lli",&c[i]);
        sort(c,c+m);

        vector<pair<ll,ll>> v;

        for(ll i=1;i<=n;i++){
            if(a[i]<b[i]){
                printf("NO\n");
                goto read;
            }
            if(a[i]!=b[i]){
                v.pb({b[i],i});
            }
        }
        sort(all(v));

        for(ll i=m-1;i>=0;i--){
            //cout<<c[i]<<" "<<v.size()<<endl;
            if(v.size()==0) break;
            if(v.size()==1){
                if(c[i]==v[0].first) v.pop_back();
                continue;
            }
            if(v[v.size()-1].first!=c[i]) continue;
            ll cnt=1;
            for(ll j=v.size()-2;j>=0;j--){
                if(v[j].first!=c[i]) break;
                ll val=query(1,1,n,v[j].second,v[j+1].second);
                //cout<<v[j].first<<" "<<v[j].second<<" "<<v[j+1].first<<" "<<v[j+1].second<<" "<<val<<endl;
                if(val>c[i]) break;
                cnt++;
            }
            while(cnt--) v.pop_back();
        }

        if(v.size()) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;

    }

    return 0;
}