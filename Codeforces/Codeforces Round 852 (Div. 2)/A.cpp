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
        ll a,b,n,m;
        cin>>a>>b>>n>>m;
        ll ans=0;
        if(m*a<=(m+1)*b){
            ll x=n/(m+1);
            ans=a*x*m;
        }
        else{
            ll x=n/(m+1);
            ans=b*x*(m+1);
        }
        n%=(m+1);
        if(a<b) ans+=a*n;
        else ans+=b*n;
        cout<<ans<<"\n";
    }

    return 0;
}