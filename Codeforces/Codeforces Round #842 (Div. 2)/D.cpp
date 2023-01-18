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

ll p[200007],cnt;

ll find_par(ll x){
    if(x==p[x]) return x;
    else return p[x]=find_par(p[x]);
}

void conn(ll u,ll v){
    u=find_par(u);
    v=find_par(v);
    if(u!=v){
        cnt--;
        p[u]=v;
    }
}

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll a[n+1];
        cnt=n;
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
            a[x]=i;
            p[i]=i;
        }

        for(ll i=1;i<=n;i++){
            conn(i,a[i]);
        }

        ll ans=n-cnt+1;
        for(ll i=2;i<=n;i++){
            ll u=find_par(i);
            ll v=find_par(i-1);
            ll temp=cnt;
            if(u==v){
                ans-=2;
                break;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}