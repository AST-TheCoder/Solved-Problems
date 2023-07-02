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

        ll x;
        for(x=0;x<=n;x++){
            ll a=(x*(x-1))/2;
            ll d=n-x;
            ll b=(d*(d-1))/2;
            if(a+b==k) break;
        }

        if(x==n+1){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        for(ll i=1;i<=n;i++){
            if(i<=x) cout<<1<<" ";
            else cout<<-1<<" ";
        }cout<<endl;
    }

    return 0;
}