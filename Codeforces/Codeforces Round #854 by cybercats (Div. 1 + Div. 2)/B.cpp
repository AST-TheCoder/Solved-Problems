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

        pair<ll,ll> a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i+1;
        }
        sort(a,a+n);

        if(a[0].first==a[n-1].first){
            cout<<0<<endl;
            continue;
        }
        if(a[0].first==1){
            cout<<-1<<endl;
            continue;
        }

        vector<pair<ll,ll>> ans;
        while(a[0].first!=a[n-1].first){
            for(ll i=1;i<n;i++){
                while(a[i].first>a[0].first){
                    a[i].first=ceil((double)a[i].first/(double)a[0].first);
                    ans.pb({a[i].second,a[0].second});
                }
                if(a[i].first<a[0].first) break;
            }
            sort(a,a+n);
        }
        //for(ll i=0;i<n;i++) cout<<a[i].first<<" ";cout<<endl;
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;

    }

    return 0;
}