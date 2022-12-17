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

    ll n,m;
    cin>>n>>m;

    ll a[n];
    for(ll i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);

    ll ans=1;
    for(ll i=0,j=n-1;i<=j;){
        //cout<<i<<" "<<j<<endl;
        if(i==j){
            ans+=a[i];
            break;
        }
        else{
            if(a[i]+a[j]<=m){
                ans+=a[i]+a[j];
                i++,j--;
            }
            else{
                ans+=a[j]+1;
                j--;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}