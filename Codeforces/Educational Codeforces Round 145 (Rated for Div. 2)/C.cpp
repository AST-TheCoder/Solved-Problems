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

        ll a[n+1];
        memset(a,0,sizeof(a));
        for(ll i=1;i<=n;i++){
            if(i*(i+1)/2>k){
                k-=(i*(i-1))/2;
                ll id=i-k-1;
                a[i]=-(2*id+1);
                break;
            }
            a[i]=2;
        }
        for(ll i=1;i<=n;i++){
            if(!a[i]) a[i]=-1000;
            cout<<a[i]<<" ";
        }cout<<endl;
    }

    return 0;
}