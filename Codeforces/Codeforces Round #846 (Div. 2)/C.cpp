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
        ll cnt[2001];
        memset(cnt,0,sizeof(cnt));
        ll n,m;
        cin>>n>>m;

        ll a[n],b[m];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        for(ll i=0;i<m;i++) cin>>b[i];

        priority_queue<ll> c;
        for(ll i=1;i<=2000;i++){
            if(cnt[i]) c.push(cnt[i]);
        }
        sort(b,b+m,greater<ll>());

        ll ans=0;
        for(ll i=0;i<m && !c.empty();i++){
            ll val=c.top();
            //cout<<val<<" "<<b[i]<<endl;
            c.pop();
            if(b[i]>=val){
                ans+=val;
            }
            else{
                ans+=b[i];
                c.push(val-b[i]);
            }
        }
        
        
        cout<<ans<<endl;
    }

    return 0;
}