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
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        ll c[200];
        memset(c,0,sizeof(c));
        for(ll i=0;i<s.size();i++){
            c[s[i]]++;
        }

        ll x=0;
        for(ll i='a';i<='z';i++){
            x+=c[i]%2;
        }
        if(k>=x-1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    

    return 0;
}