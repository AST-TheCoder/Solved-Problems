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

    read:
    while(t--){
        ll n,k;
        cin>>n>>k;

        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];

        for(ll i=1,p=n;i<=min(n,k);i++){
            if(a[p]>n){
                cout<<"No"<<endl;
                goto read;
            }
            p-=a[p];
            if(p<=0) p+=n;
        }
        cout<<"Yes"<<endl;
    }

    return 0;
}