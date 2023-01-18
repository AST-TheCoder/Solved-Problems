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

        ll a[n*n];
        for(ll i=0,j=1;i<n*n;i+=2,j++) a[i]=j;
        for(ll i=1,j=n*n;i<n*n;i+=2,j--) a[i]=j;

        for(ll i=1,j=0;i<=n;i++){
            if(i%2==0){
                reverse(a+(i-1)*n,a+i*n);
            }
            for(;j<i*n;j++) cout<<a[j]<<" ";
            cout<<endl;
        }
    }

    return 0;
}