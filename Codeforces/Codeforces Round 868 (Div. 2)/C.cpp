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

ll sc[4000];
vector<ll> p;
ll cnt[4000];

int main()
{

    for(ll i=2;i<4000;i++){
        if(sc[i]==0){
            p.pb(i);
            for(ll j=i;j<4000;j+=i) sc[j]=1;
        }
    }

    ll t;
    cin>>t;

    while(t--){
        memset(cnt,0,sizeof(cnt));
        ll n;
        cin>>n;
        vector<ll> temp;

        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            for(ll j=0;j<p.size() && p[j]*p[j]<=x;j++){
                ll c=0;
                while(x%p[j]==0){
                    c++;
                    x/=p[j];
                }
                cnt[p[j]]+=c;
            }
            if(x!=1){
                if(x<4000) cnt[x]++;
                else temp.pb(x);
            }
        }

        ll ans=0,v=0;
        for(ll i=2;i<4000;i++){
            ans+=cnt[i]/2;
            v+=cnt[i]%2;
        }

        ll c=0;
        sort(all(temp));
        if(temp.size()) c=1;
        for(ll i=1;i<temp.size();i++){
            if(temp[i]==temp[i-1]) c++;
            else{
                ans+=c/2;
                v+=c%2;
                c=1;
            }
        }
        ans+=c/2;
        v+=c%2;
        ans+=v/3;

        cout<<ans<<endl;
    }

    return 0;
}