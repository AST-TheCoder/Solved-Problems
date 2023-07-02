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
    scanf("%lli",&t);
    while(t--){
        ll n,m;
        scanf("%lli %lli",&m,&n);
        ll a[n][m];
        for(ll j=0;j<m;j++){
            for(ll i=0;i<n;i++){
                scanf("%lli",&a[i][j]);
            }
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            sort(a[i],a[i]+m);
            for(ll j=m-2,c=1;j>=0;j--){
                ans+=a[i][j+1]-c*a[i][j];
                a[i][j]+=a[i][j+1];
                c++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}