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
        ll n,k,x;
        cin>>n>>k>>x;

        if(n<k || x<k-1){
            cout<<-1<<endl;
            continue;
        }

        ll ans=0,m=n;
        for(ll i=0;i<k;i++){
            ans+=i;
            m--;
        }

        for(ll i=0;i<m;i++){
            if(x!=k) ans+=x;
            else ans+=x-1;
        }

        cout<<ans<<endl;
        
    }

    return 0;
}