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

        if(n%2==0){
            for(ll i=1;i<=n/2;i++) cout<<n-i<<" "<<n+i<<" ";
            cout<<endl;
            continue;
        }

        ll l=n-n/2+1;
        ll r=l+n+1;
        for(ll i=1;i<=n/2;i++){
            cout<<l<<" "<<r<<" ";
            l++,r--;
        }
        cout<<r<<endl;
    }

    return 0;
}