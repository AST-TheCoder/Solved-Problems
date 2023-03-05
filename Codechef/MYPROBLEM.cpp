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
    vector<ll> p;
    p.pb(1);
    for(ll i=1;i<=12;i++) p.pb(p[i-1]*10);

    ll t;
    cin>>t;

    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans=Max;
        for(ll i=2;i<(1<<10);i++){
            vector<ll> temp;
            for(ll j=0;j<10;j++){
                if(i&(1<<j)) temp.pb(j);
            }

            if(temp.size()>k) continue;
        }
    }

    return 0;
}