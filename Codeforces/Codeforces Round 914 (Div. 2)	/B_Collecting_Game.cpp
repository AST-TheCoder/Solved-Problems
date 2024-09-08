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

        ll ans[n],s=0;
        pair<ll,ll> x[n];
        for(ll i=0;i<n;i++){
            cin>>x[i].first;
            x[i].second=i;
            s+=x[i].first;
        }
        sort(x,x+n);

        for(ll i=n-1;i>=0;i--){
            if(i==n-1) ans[x[i].second]=i;
            else{
                if(s>=x[i+1].first) ans[x[i].second]=ans[x[i+1].second];
                else ans[x[i].second]=i;
            }
            s-=x[i].first;
        }
        for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}