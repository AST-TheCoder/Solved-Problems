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
        ll a[n+1];
        memset(a,0,sizeof(a));
        string p;
        cin>>p;
        p="#"+p;

        ll z[n+1],o[n+1];
        memset(z,0,sizeof(z));
        memset(o,0,sizeof(o));

        for(ll i=1;i<=n;i++){
            if(p[i]=='0') z[i]++;
            else o[i]++;

            z[i]+=z[i-1];
            o[i]+=o[i-1];
        }

        ll x[n+1];
        memset(x,-1,sizeof(x));

        for(ll i=0;i<=k;i++){
            ll lfz[n+2],rtz[n+2];
            memset(lfz,0,sizeof(lfz));
            memset(rtz,0,sizeof(rtz));
            for(ll l=1,r=1;r<=n;r++){
                while(o[r]-o[l-1]>k-i && l<=r) l++;
                lfz[r]=max(lfz[r-1],r-l+1);
            }
            for(ll l=n,r=n;l>=1;l--){
                while(o[r]-o[l-1]>k-i && l<=r) r--;
                rtz[l]=max(rtz[l+1],r-l+1);
            }
            ll lfo[n+2],rto[n+2];
            memset(lfo,0,sizeof(lfo));
            memset(rto,0,sizeof(rto));
            for(ll l=1,r=1;r<=n;r++){
                while(z[r]-z[l-1]>i && l<=r) l++;
                lfo[r]=max(lfo[r-1],r-l+1);
            }
            for(ll l=n,r=n;l>=1;l--){
                while(z[r]-z[l-1]>i && l<=r) r--;
                rto[l]=max(rto[l+1],r-l+1);
            }

            for(ll j=1;j<=n+1;j++){
                x[lfz[j-1]]=max(x[lfz[j-1]],rto[j]);
                x[rtz[j]]=max(x[rtz[j]],lfo[j-1]);
            }
        }

        for(ll i=0;i<=n;i++){
            if(x[i]==-1) continue;
            for(ll j=1;j<=n;j++) a[j]=max(a[j],i*j+x[i]);
        }

        
        for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
        cout<<endl;
    }

    return 0;
}