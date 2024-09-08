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

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];
        ll b=0;
        for(ll i=0;i<m;i++){
            ll x;
            cin>>x;
            b|=x;
        }
        ll mn=0,mx=0;
        if(n%2){
            for(ll i=0;i<n;i++){
                mx^=(a[i]|b);
                mn^=a[i];
            }
        }
        else{
            for(ll i=0;i<n;i++){
                mx^=a[i];
                mn^=(a[i]|b);
            }
        }
        cout<<mn<<" "<<mx<<endl;
    }

    return 0;
}