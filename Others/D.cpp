#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define     fast            ios_base::sync_with_stdio(false);cin.tie(NULL)
#define     input           freopen('input.txt', 'r', stdin)
#define     output          freopen('output.txt', 'w', stdout)
#define     ll              long long int
#define     F               first
#define     S               second
#define     mem(a,v)        memset(a,v,sizeof(a))
#define     Max             1000000000000000007
#define     pb              push_back
#define     mp              make_pair
#define     PI              3.14159265358979323846 // acos(-1)  // 2.0 * acos(0.0)
//............................Lets Start.....................................//
 
 const int N= 3e5+5;
 ll cnt1[N],cnt2[N],mod=998244353,fact[N];
 
int main(){
    ll t=1;
    fact[0]=1;
    for(ll i=1;i<N;i++) fact[i]=(fact[i-1]*i)%mod; //cin>>t;
    while(t--){
        ordered_set<ll> st;
        ll n,m; 
        cin>>n>>m;
        ll a[n],b[m];
        for(ll i=0;i<n;i++){
            cin>>a[i],st.insert(a[i]),cnt1[a[i]]++;
        }
        for(ll i=0;i<m;i++) cin>>b[i],cnt2[b[i]]++;

        ll ans=0,chk=1;
//cout<<"ok"<<endl;
        for(ll i=0;i<m;i++){
            ll dist=st.order_of_key(b[i]);
            ll sz= st.size();
            ll cur= (dist*fact[sz-1])%mod;
            
            ans= (ans+cur*chk)%mod; 
            // chk=cnt1[b[i]]*chk;
            // chk%=mod;
            if(dist>=st.size() || *st.find_by_order(dist)!=b[i]){
                break;
            }
            st.erase(st.find_by_order(st.order_of_key(b[i])));
        }
        cout<<ans<<endl;

    }
}