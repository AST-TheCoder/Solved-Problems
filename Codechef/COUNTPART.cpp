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

        ll n,mod=998244353;
        cin>>n;

        ll a[n+1];
        for(ll i=0;i<n;i++) cin>>a[i];
        a[n]=n+1;

        deque<pair<ll,ll>> q;
        q.push_back({n+1,n});

        ll id[n+1];
        for(ll i=n-1;i>=0;i--){
            while(q.back().first<a[i]) q.pop_back();
            id[i]=q.back().second;
            if(i+1==id[i] && i!=n-1) id[i]=id[i+1];
            q.push_back({a[i],i});
        }
        
        ll ans[n+2];
        ans[n+1]=0;
        ans[n]=1;
        for(ll i=n-1;i>=0;i--){
            ll j=id[i]+1;
            ans[i]=(ans[i+1]-ans[j]+mod)%mod;
            if(i) ans[i]=(ans[i]+ans[i+1])%mod;
        }

        cout<<ans[0]<<endl;
    }

    return 0;
}