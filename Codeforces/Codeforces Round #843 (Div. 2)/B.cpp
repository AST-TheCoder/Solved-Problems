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

ll chk[200007];

int main()
{

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        vector<ll> a[n];

        for(ll i=0;i<n;i++){
            ll k;
            cin>>k;
            for(ll j=0;j<k;j++){
                ll x;
                cin>>x;
                a[i].pb(x);
                chk[x]++;
            }
        }

        ll f=0;
        for(ll i=0;i<n;i++){
            ll ok=0;
            for(ll j=0;j<a[i].size();j++){
                ll v=a[i][j];
                if(chk[v]<=1){
                    ok=1;
                    break;
                }
            }
            if(!ok){
                f=1;
                break;
            }
        }

        if(f) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        for(ll i=0;i<n;i++){
            for(ll j=0;j<a[i].size();j++){
                ll v=a[i][j];
                chk[v]=0;
            }
        }
    }

    return 0;
}