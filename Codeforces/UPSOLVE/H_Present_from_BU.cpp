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

    ll n;
    cin>>n;

    string s;
    cin>>s;

    s+=s;

    ll mod=1000000009,base=31;
    ll b[400001];
    b[0]=1;
    for(ll i=1;i<=400000;i++){
        b[i]=(b[i-1]*base)%mod;
    }

    ll hash[2*n+1];
    for(ll i=0,h=0;i<2*n;i++){
        h=(h*base+(s[i]-'a'))%mod;
        if(i-n+1>=0){
            hash[i-n+1]=h;
            h=(h-(s[i-n+1]-'a')*b[n-1]+(s[i-n+1]-'a')*mod)%mod;
        }
    }

    ll revhash[2*n+1];
    for(ll i=2*n-1,h=0;i>=0;i--){
        h=(h*base+(s[i]-'a'))%mod;
        if(i<=n){
            revhash[i]=h;
            h=(h-(s[i+n-1]-'a')*b[n-1]+(s[i+n-1]-'a')*mod)%mod;
        }
    }
    ll ans=0;
    for(ll i=0;i<n;i++){
        if(hash[i]==revhash[i]) ans++;
    }
    cout<<ans<<endl;

    return 0;
}