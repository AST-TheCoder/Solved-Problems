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

    ll t=1;
    //cin>>t;


    while(t--){
        ll n;
        cin>>n;

        ll a[n],mod=998244353;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        ll ans=0,p=1;
        for(ll i=0;i<=30;i++){
            string s;
            for(ll j=0;j<n;j++){
                if(a[j]&(1<<i)) s+='1';
                else s+='0';
            }
            s+='1';

            ll c=0;
            vector<ll> len;
            for(ll j=0;j<s.size();j++){
                c++;
                if(s[j]=='1'){
                    len.pb(c);
                    c=0;
                }
            }

            ll o=0,e=0,u=0,v=0;
            for(ll j=0;j<len.size()-1;j++){
                o+=u*len[j];
                o%=mod;
                e+=v*len[j];
                e%=mod;
                ll x=len[j+1]-1;
                if(j%2){
                    u+=len[j];
                    u%=mod;
                    o+=(len[j]*(len[j]+1))/2;
                    o%=mod;
                    ans+=o*p;
                    ans%=mod;
                    ll temp=(x*o)%mod;
                    ans+=(temp*p);
                    ans%=mod;
                    x=(x*(x+1))/2;
                    x%=mod;
                    temp=(x*u)%mod;
                    ans+=(temp*p);
                    ans%=mod;
                }
                else{
                    v+=len[j];
                    v%=mod;
                    e+=(len[j]*(len[j]+1))/2;
                    e%=mod;
                    ans+=e*p;
                    ans%=mod;
                    ll temp=(x*e)%mod;
                    ans+=(temp*p);
                    ans%=mod;
                    x=(x*(x+1))/2;
                    x%=mod;
                    temp=(x*v)%mod;
                    ans+=(temp*p);
                    ans%=mod;
                }
            }
            p*=2;
        }
        cout<<ans<<endl;
    }

    return 0;
}