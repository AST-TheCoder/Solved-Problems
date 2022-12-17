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
    scanf("%lli",&t);

    while(t--){
        ll n;
        scanf("%lli",&n);

        ll a[n];
        for(ll i=0;i<n;i++){
            ll x;
            scanf("%lli",&x);

            ll p=log2(x);
            p=ceil(pow(2,p+1));
            a[i]=p-x;
        }
        printf("%lli\n",n);
        for(ll i=0;i<n;i++){
            printf("%lli %lli\n",i+1,a[i]);
        }
    }

    return 0;
}