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

        ll chk[n+1];
        memset(chk,0,sizeof(chk));
        ll a[n+1];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            chk[a[i]]=1;
        }
        for(ll i=0;i<=n;i++){
            if(!chk[i]){
                a[n]=i;
                break;
            }
        }
        k%=n+1;
        ll ans[n+1];
        for(ll i=0;i<=n;i++){
            ans[(i+k)%(n+1)]=a[i];
        }
        for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}