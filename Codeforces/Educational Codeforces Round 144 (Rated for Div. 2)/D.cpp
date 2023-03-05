#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 100000000000000000

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

        ll a[n+1];
        a[0]=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            a[i]-=x;
            a[i]+=a[i-1];
        }

        ll mx[n+1],id=n,val=-Max;
        ll ans=0;
        for(ll i=n;i>=1;i--){
            mx[i]=id;
            if(a[i]>=val){
                val=a[i];
                id=i;
            }
            //cout<<a[i]<<endl;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1,l=i;j<=k && l<=n;j++,l++){
                ll temp=a[l]-a[i-1]+(2*j*x);
                ans=max(ans,temp);
            }
            id=mx[i];
            if(id-i+1<=k) continue;
            ll temp=a[id]-a[i-1]+(2*k*x);
            ans=max(ans,temp);
        }
        for(ll i=1;i<=n;i++){
            if(i<=k){
                ll m=-Max;
                for(ll j=i;j<=n-k+i-1;j++){
                    m=max(m,a[j]);
                }
                for(ll j=n-k+i,l=1;j<=n;j++,l++){
                    m=max(m,a[j]+(2*l*x));
                }
                ans=max(ans,m-a[i-1]);
                continue;
            }
            ans=max(ans,a[i]-a[i-1]);
            if(i!=n){
                ans=max(ans,a[mx[i]]-a[i-1]);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}