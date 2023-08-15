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

    ll p;
    cin>>p;
    ll n=ceil(pow(2,p));

    ll a[n+1],q[n+1],ans=1,mod=998244353;
    memset(q,-1,sizeof(q));
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=-1) q[a[i]]=i;
    }

    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    for(ll i=n;i>2;i/=2){
        ll l=i/2+1,r=i,d=2*n/i;
        ll c=r-l+1;
        for(ll j=1;j<=n;j++) if(a[j]>=l && a[j]<=r) c--;
        for(ll j=1;j<=n;j+=d){
            ll x=0,y=0;
            for(ll k=j;k<j+d;k++){
                if(a[k]==-1) x++;
                else if(a[k]>=l && a[k]<=r) y++;
            }
            if(y>1) ans=0;
            if(!y){
                ans=(ans*x)%mod;
                ans=(ans*c)%mod;
                for(ll k=j;k<j+d;k++){
                    if(a[k]==-1){
                        a[k]=l;
                        break;
                    }
                }
                c--;
            }
        }
    }

    if(q[1]==-1 && q[2]==-1) ans=(ans*2)%mod;
    else if(q[1]!=-1 && q[2]!=-1){
        if(q[1]<=n/2 && q[2]<=n/2) ans=0;
        if(q[1]>n/2 && q[2]>n/2) ans=0;
    } 

    cout<<ans<<endl;

    return 0;
}