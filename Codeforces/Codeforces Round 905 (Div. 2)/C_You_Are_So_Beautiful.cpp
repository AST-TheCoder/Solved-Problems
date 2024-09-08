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
        ll n;
        cin>>n;

        ll a[n];
        vector<pair<ll,ll>> x;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            x.pb({a[i],i});
        }
        sort(all(x));
        for(ll i=0,c=0;i<n;i++){
            if(i && x[i].first!=x[i-1].first) c++;
            a[x[i].second]=c;
        }
        ll c[n];
        memset(c,0,sizeof(c));
        min_heap<ll> q;
        for(ll i=n-1;i>=0;i--){
            if(!c[a[i]]){
                q.push(i);
            }
            c[a[i]]=i;
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            while(!q.empty() && q.top()<i) q.pop();
            if(c[a[i]]==i) ans+=q.size();
        }
        cout<<ans<<endl;
    }

    return 0;
}