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
        ll n,m;
        cin>>n>>m;
        set<ll> temp;
        vector<ll> a;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            temp.insert(x);
        }

        for(auto x: temp){
            a.pb(x);
        }
        n=a.size();

        ll chk[m+1];
        memset(chk,0,sizeof(chk));
        ll ans=Max,c=0;
        for(ll i=0,j=-1;;){
            ll val;

            if(c==m){
                ans=min(ans,a[j]-a[i]);

                val=a[i];
                i++;
                for(ll k=1;k*k<=val;k++){
                    if(val%k) continue;
                    if(k<=m){
                        chk[k]--;
                        if(!chk[k]) c--;
                    }
                    if(k==val/k) continue;
                    ll d=val/k;
                    if(d<=m){
                        chk[d]--;
                        if(!chk[d]) c--;
                    }
                }
                continue;
            }
            j++;
            if(j==n) break;
            val=a[j];
            for(ll k=1;k*k<=val;k++){
                if(val%k) continue;
                if(k<=m){
                    if(!chk[k]) c++;
                    chk[k]++;
                }
                if(k==val/k) continue;
                ll d=val/k;
                if(d<=m){
                    if(!chk[d]) c++;
                    chk[d]++;
                }
            }
        }
        if(ans==Max) ans=-1;
        cout<<ans<<"\n";
    }

    return 0;
}