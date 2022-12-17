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
        ll n,f=0;
        cin>>n;

        string s;
        cin>>s;

        for(ll i=1;i<n;i+=3){
            if(i+1==n || s[i]!=s[i+1]) f=1;
        }

        if(f) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}