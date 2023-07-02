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

ll chk[50001];
int main()
{

    ll t;
    cin>>t;

    read:
    while(t--){
        ll m;
        cin>>m;
        set<ll> s;
        for(ll i=0;i<m;i++){
            ll k;
            cin>>k;
            for(ll j=0;j<k;j++){
                ll x;
                cin>>x;
                chk[x]=i+1;
                s.insert(x);
            }
        }

        ll ans[m+1];
        memset(ans,-1,sizeof(ans));
        for(auto x: s){
            ans[chk[x]]=x;
            chk[x]=0;
        }
        for(ll i=1;i<=m;i++){
            if(ans[i]==-1){
                cout<<-1<<"\n";
                goto read;
            }
        }
        for(ll i=1;i<=m;i++) cout<<ans[i]<<" ";
        cout<<"\n";
    }

    return 0;
}