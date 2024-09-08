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
ll c[4000001];
int main()
{
    freopen("back_in_black_chapter_1_input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        string s;
        cin>>s;
        s="#"+s;
        for(ll i=0;i<=n;i++) c[i]=0;

        ll q;
        cin>>q;

        while(q--){
            ll x;
            cin>>x;
            c[x]++;
        }

        for(ll i=n;i>=1;i--){
            for(ll j=i+i;j<=n;j+=i){
                c[j]+=c[i];
            }
        }

        ll ans=0;
        for(ll i=1;i<=n;i++){
            ll ok=0;
            if(s[i]=='0' && c[i]%2==1) ok=1;
            if(s[i]=='1' && c[i]%2==0) ok=1;

            ans+=ok;
            for(ll j=i+i;j<=n;j+=i){
                c[j]+=ok;
            }
        }
        cout<<"Case #"<<++ii<<": "<<ans<<endl;
    }

    return 0;
}