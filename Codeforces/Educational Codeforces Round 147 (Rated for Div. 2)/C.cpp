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
        string s;
        cin>>s;

        vector<ll> pos[200];
        for(ll i='a';i<='z';i++) pos[i].pb(0);
        for(ll i=0;i<s.size();i++){
            pos[s[i]].pb(i+1);
        }
        for(ll i='a';i<='z';i++) pos[i].pb(s.size()+1);

        ll ans=Max;
        for(ll i='a';i<='z';i++){
            ll m=0;
            for(ll j=1;j<pos[i].size();j++){
                m=max(m,pos[i][j]-pos[i][j-1]-1);
            }
            ll c=0;
            while(m){
                m/=2;
                c++;
            }
            ans=min(ans,c);
        }
        cout<<ans<<endl;
    }

    return 0;
}