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

        ll gcd=Max;
        for(ll i=0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                gcd=min(gcd,__gcd(a[i],a[j]));
            }
        }

        if(gcd<=2) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}