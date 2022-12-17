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

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        ll c[n+1];
        memset(c,0,sizeof(c));

        for(ll i=0;i<m;i++){
            ll x,y;
            cin>>x>>y;
            if(x>y) swap(x,y);
            c[y]=max(c[y],x);
        }

        for(ll i=1;i<=n;i++) c[i]=max(c[i],c[i-1]);

        ll ans=0;
        for(ll i=1;i<=n;i++) ans+=i-c[i];
        cout<<ans<<endl;
    }

    return 0;
}