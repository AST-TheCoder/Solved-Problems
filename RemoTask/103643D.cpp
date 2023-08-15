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
    string s,t;
    cin>>s>>t;

    ll a[26],b[26];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));

    for(ll i=0;i<n;i++){
        a[s[i]-'a']++;
        b[t[i]-'a']++;
    }
    ll ans=0;
    for(ll i=0;i<26;i++){
        if(a[i]<b[i]) ans+=(b[i]-a[i]);
    }

    cout<<ans<<endl;

    return 0;
}