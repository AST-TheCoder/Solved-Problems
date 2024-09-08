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
        ll n,m,d;
        cin>>n>>m>>d;

        ll a[m];
        for(ll i=0;i<m;i++) cin>>a[i];

        vector<ll> pos;
        if(a[0]!=1) pos.pb(1);
        for(ll i=0;i<m;i++) pos.pb(a[i]);
        pos.pb(n+1);

        ll tot=pos.size()-1;
        for(ll i=1;i<pos.size();i++){
            ll len=pos[i]-pos[i-1]-1;
            tot+=len/d;
        }

        ll ans=tot,cnt=(a[0]==1);
        for(ll i=1;i<pos.size()-1;i++){
            ll temp=tot;
            ll len=pos[i]-pos[i-1]-1;
            temp-=len/d;
            len=pos[i+1]-pos[i]-1;
            temp-=len/d;
            len=pos[i+1]-pos[i-1]-1;
            temp+=len/d;
            temp--;
            if(temp<ans){
                ans=temp;
                cnt=1;
            }
            else if(temp==ans) cnt++;
        }

        cout<<ans<<" "<<cnt<<endl;
    }

    return 0;
}