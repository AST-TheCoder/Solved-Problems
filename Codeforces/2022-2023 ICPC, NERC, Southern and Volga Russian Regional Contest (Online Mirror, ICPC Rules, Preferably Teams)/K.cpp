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

    ll n,s=0,m=Max;
    cin>>n;

    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            ll x;
            cin>>x;
            s+=x;
            if(i==n-j+1) m=min(m,x);
        }
    }
    cout<<s-m<<endl;

    return 0;
}