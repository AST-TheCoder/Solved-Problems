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
        for(ll i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);

        ll c=1,ans=0;
        for(ll i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                ans+=(c*(c-1))/2;
                c=0;
            }
            c++;
            if(i==n-1) ans+=(c*(c-1))/2;
        }
        cout<<ans<<endl;
    }

    return 0;
}