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
            cout<<"NO"<<"\n";
            continue;
        }
        cout<<"YES"<<"\n";
        for(ll i=1,j=2*n;i<=(n+1)/2;i++,j-=2){
            cout<<i<<" "<<j<<"\n";
        }
        for(ll i=(n+1)/2+1,j=2*n-1;i<=n;i++,j-=2){
            cout<<i<<" "<<j<<"\n";
        }
    }

    return 0;
}