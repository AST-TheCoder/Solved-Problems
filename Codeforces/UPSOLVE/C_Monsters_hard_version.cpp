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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;


int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        ll a[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }

        ll ans=0,mx=0;
        ordered_set<ll> s,x;

        for(ll i=1;i<=n;i++){
            ll id1=s.order_of_key(a[i]);
            ans+=a[i]-id1-1;
            ll idx=x.order_of_key(a[i]);
            if(idx==x.size()){
                ll id2=s.size()-id1;
                ans-=id2;
                s.insert(a[i]);
                ll id=s.order_of_key(a[i]+1);
                if(id==a[i]) x.insert(a[i]);
            }
            else{
                ll val=*x.find_by_order(idx);
                ans-=(val-a[i]);
                s.erase(s.find_by_order(s.order_of_key(val)));
                s.insert(a[i]);
                ll id=s.order_of_key(a[i]+1);
                if(id==a[i]) x.insert(a[i]);
            }
        }
    }
    

    return 0;
}