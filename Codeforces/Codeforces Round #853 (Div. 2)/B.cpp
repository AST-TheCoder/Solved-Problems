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
        ll n;
        cin>>n;

        string s;
        cin>>s;

        vector<ll> v;
        for(ll i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]) v.pb(i);
        }

        ll chk=0;
        for(ll i=1;i<v.size();i++){
            if(abs(v[i]-v[i-1])>1) chk=1;
        }
        if(chk) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}