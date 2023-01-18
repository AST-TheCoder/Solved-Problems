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
        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1);

        ll ans=1;
        for(ll i=2,c=1;i<=n;i++){
            if(a[i]!=a[i-1]){
                ans=max(ans,c);
                c=0;
            }
            c++;
            if(i==n) ans=max(ans,c);
        }

        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=n;j++){
                if(a[i]==a[j]) continue;
                ll d=a[j]-a[i];
                vector<ll> div;
                for(ll k=1;k*k<=d;k++){
                    if(d%k==0){
                        div.pb(k);
                        ll temp=d/k;
                        if(temp==k) continue;
                        div.pb(temp);
                    }
                }

                for(ll k=0;k<div.size();k++){
                    ll v=div[k];
                    ll temp=d/div[k];
                    if(v%2!=temp%2) continue;
                    v/=2;
                    if(div[k]%2) temp-=(2*v);
                    else{
                        temp-=(2*v);
                        temp++;
                    }
                    temp=(temp+1)/2;
                    temp--;
                    if(temp<=0) continue;
                    temp*=temp;
                    ll x=temp-a[i];
                    if(x<0 || x>1000000000000000000) continue;
                    ll cnt=0;
                    for(ll l=1;l<=n;l++){
                        temp=a[l]+x;
                        ll chk=sqrt(temp);
                        if(chk*chk==temp) cnt++;
                    }
                    ans=max(ans,cnt);
                }
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}