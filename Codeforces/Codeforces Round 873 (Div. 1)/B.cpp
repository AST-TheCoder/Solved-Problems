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

        ll a[n+2],ans=0,prev[n+2],next[n+2];
        a[0]=Max;
        a[n+1]=-Max;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            ans+=i*(n-i);
        }
        //cout<<ans<<endl;
        for(ll i=1;i<=n;i++){
            ll p,q;
            for(p=i-1;p>=0;p--){
                if(a[p]>a[i]) break;
            }
            for(q=i+1;q<=n+1;q++){
                if(a[q]<a[i]) break;
            }
            //cout<<i<<" "<<p<<" "<<q<<" -- ";
            prev[i]=p;
            next[i]=q;
        }
        for(ll i=1;i<=n;i++){
            
        }
        cout<<ans<<endl;
    }

    return 0;
}