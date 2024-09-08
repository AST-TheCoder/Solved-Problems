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
        ll n,k;
        cin>>n>>k;

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        ll ans=k-1;
        if(k==4){
            ll c=0;
            for(ll i=0;i<n;i++){
                if(a[i]%4==0) c+=2;
                else if(a[i]%2==0) c++;
            }
            if(c>=2) ans=0;
            else ans=2-c;
        }

        for(ll i=0;i<n;i++){
            ll x=a[i]%k;
            if(x) x=k-x;
            ans=min(ans,x);
        }
        cout<<ans<<endl;
    }

    return 0;
}