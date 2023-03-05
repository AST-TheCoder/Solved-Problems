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
        ll n,m,d;
        cin>>n>>m>>d;

        ll pos[n+1];
        for(ll i=1;i<=n;i++){
            ll x;
            cin>>x;
            pos[x]=i;
        }
        ll a[m];
        for(ll i=0;i<m;i++){
            cin>>a[i];
        }

        ll ans=Max;
        for(ll i=0;i<m-1;i++){
            ll p=pos[a[i]];
            ll q=pos[a[i+1]];
            if(q<p || q>p+d){
                ans=0;
                continue;
            }
            ll dif=q-p;
            ans=min(ans,dif);
            if(d<=n-2) ans=min(ans,d-dif+1);
        }
        cout<<ans<<"\n";

    }

    return 0;
}