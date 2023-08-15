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
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        ll l=1,r=a[n]*k+1,ans=r;
        while(l<=r){
            ll m=(l+r)/2;
            ll x=m,op=k;
            for(ll i=n;i>=1;i--){
                if(a[i]>x) continue;
                ll d=x-a[i];
                d=d/i+1;
                if(d>op) d=op;
                x-=d*i;
                op-=d;
                if(!op) break;
            }
            //cout<<l<<" "<<r<<" "<<m<<" "<<x<<" "<<op<<endl;
            if(x>0){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        cout<<ans<<endl;
    }

    return 0;
}