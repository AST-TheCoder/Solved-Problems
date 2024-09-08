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
    read:
    while(t--){
        ll n,m;
        cin>>n>>m;
        vector<ll> ans;
        ans.pb(n);

        ll p=-1,q=-1;

        for(ll i=0; i<63; i++){
            if((n & (1LL<<i)) && !(m & (1LL<<i))) p = i;
        }
        for(ll i=0; i<63; i++){
            if(i==p) continue;
            if(n & (1LL<<i)) q=i;
        }

        ll x=0;
        for(ll i=0; i<min(p,q); i++){
            if(p==-1 || q==-1) break;
            if(!(n & (1LL<<i)) && (m & (1LL<<i))) x+=(1LL<<i);
        }
        if(x){
            x+=(1LL<<p);
            n^=x;
            ans.pb(n);
        }

        for(ll i=0; i<63; i++){
            if((n & (1LL<<i)) == (m & (1LL<<i))) continue;
            if(!(m & (1LL<<i))){
                if(n == (1LL<<i)){
                    cout<<-1<<endl;
                    goto read;
                }
                n^=(1LL<<i);
                ans.pb(n);
                continue;
            }
            else{
                cout<<-1<<endl;
                goto read;
            }
        }

        cout<<ans.size()-1<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}