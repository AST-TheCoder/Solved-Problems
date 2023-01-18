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

        ll a[12],mx=0,mn=0;
        memset(a,0,sizeof(a));

        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;

            for(ll j=0;j<12;j++){
                if(x&(1<<j)) a[j]++;
            }
        }

        for(ll i=0,p=1;i<12;i++,p*=2){
            if(a[i]==n){
                mn+=p;
            }
            if(a[i]!=0){
                mx+=p;
            }
        }

        cout<<mx-mn<<endl;

    }

    return 0;
}