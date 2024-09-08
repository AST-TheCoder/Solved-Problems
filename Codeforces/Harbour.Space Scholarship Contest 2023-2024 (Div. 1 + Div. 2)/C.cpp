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

        ll x=1;
        vector<ll> ans;
        ans.pb(n);

        while(n!=1){
            x=1;
            ll p=n;
            while(p%2==0){
                p/=2;
                x*=2;
            }
            if(p==1) break;
            n-=x;
            ans.pb(n);
        }
        x/=2;
        while(x>=1){
            ans.pb(x);
            x/=2;
        }
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}