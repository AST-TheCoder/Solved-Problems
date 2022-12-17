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

        ll s=0,a[n],ans=Max;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            s+=a[i];
        }

        if(s%2==0){
            cout<<0<<endl;
            continue;
        }

        for(ll i=0;i<n;i++){
            ll c=0,x=a[i]%2;
            while(x==a[i]%2){
                a[i]/=2;
                c++;
            }
            ans=min(ans,c);
        }

        cout<<ans<<endl;
    }

    return 0;
}