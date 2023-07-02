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

ll mod=998244353,fact[1100000],p[1100000];

int main()
{

    fact[0]=1;
    p[0]=1;
    for(ll i=1;i<1100000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        p[i]=(p[i-1]*2)%mod;
    }

    ll k;
    cin>>k;

    ll n=p[k];
    ll a[n+1],temp1=-1,temp2=-1;
    ll pos[n+1];
    memset(pos,-1,sizeof(pos));
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=-1) pos[a[i]]=i;
        if(a[i]==1) temp1=i;
        if(a[i]==2) temp2=i;
    }

    if(temp1!=-1 && temp2!=-1){
        if(temp1<=n/2 && temp2<=n/2){
            cout<<0<<endl;
            return 0;
        }
        if(temp1>n/2 && temp2>n/2){
            cout<<0<<endl;
            return 0;
        }
    }

    for(ll j=2,c=n/2;j<=k;j++,c/=2){
        vector<ll> x,y;
        for(ll i=1;i<=n;i++){
            if(a[i]==-1) continue;
            if(a[i]<=p[j-1]){
                x.pb(i/(c/2)+(i%(c/2)!=0));
            }
            if(a[i]<=p[j] &&a[i]>p[j-1]){
                y.pb(i/c+(i%c!=0));
            }
        }
        sort(all(x));
        sort(all(y));
        for(ll i=1;i<x.size();i++){
            if(x[i]==x[i-1]){
                cout<<0<<endl;
                return 0;
            }
        }
        for(ll i=1;i<y.size();i++){
            if(y[i]==y[i-1]){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    if(n==2){
        if(a[1]!=-1 || a[2]!=-1) cout<<1<<endl;
        else cout<<2<<endl;
        return 0;
    }
    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    ll ans=1;
    for(ll j=k-1,temp=2;j>=0;j--,temp*=2){
        ll c=0,d=0;
        for(ll i=p[j]+1;i<=p[j+1];i++){
            if(pos[i]==-1) c++;
        }
        if(!j) temp/=2;
        if(!j && pos[1]==-1) c++;
        for(ll i=1;i<=n;i+=temp){
            ll b=0,chk=0;
            for(ll l=i;l<i+temp;l++){
                if(a[l]==-1) b++;
                else if(a[l]>p[j] && a[l]<=p[j+1]) chk=1;
            }
            if(b==2 && !chk){
                d++;
            }
            if(!chk){
                for(ll l=i;l<i+temp;l++){
                    if(a[l]==-1){
                        a[l]=0;
                        break;
                    }
                }
            }
        }
        ll pp=(fact[c]*p[d])%mod;
        //cout<<pp<<" "<<c<<" "<<d<<endl;
        ans=(ans*pp)%mod;
    }
    cout<<ans<<endl;

    return 0;
}