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

    read:
    while(t--){
        ll n,w,h;
        scanf("%lli %lli %lli",&n,&w,&h);
        ll a[n],b[n];
        for(ll i=0;i<n;i++) scanf("%lli",&a[i]);
        for(ll i=0;i<n;i++) scanf("%lli",&b[i]);

        vector<ll> x;
        for(ll i=0;i<n;i++){
            ll lx=a[i]-w,rx=a[i]+w;
            ll ly=b[i]-h,ry=b[i]+h;

            if(ly<lx) x.pb(ly-lx);
            else if(ry>rx) x.pb(ry-rx);
            else x.pb(0);
        }
        sort(all(x));
        if(x[0]<0 && x[n-1]>0){
            cout<<"NO"<<endl;
            continue;
        }
        ll s=0;
        if(x[0]<0) s=x[0];
        else s=x[n-1];
        for(ll i=0;i<n;i++) a[i]+=s;

        for(ll i=0;i<n;i++){
            ll lx=a[i]-w,rx=a[i]+w;
            ll ly=b[i]-h,ry=b[i]+h;

            if(ly<lx || ry>rx){
                cout<<"NO"<<endl;
                goto read;
            }
        }
        cout<<"YES"<<endl;
    }

    return 0;
}