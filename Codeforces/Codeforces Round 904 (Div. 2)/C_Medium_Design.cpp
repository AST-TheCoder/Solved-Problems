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

        pair<ll,ll> a[n];
        for(ll i=0;i<n;i++) cin>>a[i].first>>a[i].second;
        sort(a,a+n);

        ll ans=0;
        min_heap<ll> q;
        for(ll i=0,c=0;i<n;i++){
            if(a[i].second==m) continue;
            while(!q.empty() && q.top()<a[i].first){
                q.pop();
                c--;
            }
            c++;
            ans=max(ans,c);
            q.push(a[i].second);
        }

        while(!q.empty()) q.pop();

        for(ll i=0,c=0;i<n;i++){
            if(a[i].first==1) continue;
            while(!q.empty() && q.top()<a[i].first){
                q.pop();
                c--;
            }
            c++;
            ans=max(ans,c);
            q.push(a[i].second);
        }
        cout<<ans<<endl;
    }

    return 0;
}