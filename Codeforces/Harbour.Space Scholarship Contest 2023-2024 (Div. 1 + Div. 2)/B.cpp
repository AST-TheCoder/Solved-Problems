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
        string s;
        cin>>n>>k>>s;
        if(k%2){
            string x,y;
            for(ll i=0;i<n;i++){
                if(i%2==0) x+=s[i];
                else y+=s[i];
            }
            sort(all(x));
            sort(all(y));
            for(ll i=0;i<x.size();i++){
                cout<<x[i];
                if(i<y.size()) cout<<y[i];
            }
            cout<<endl;
            continue;
        }

        sort(all(s));
        cout<<s<<endl;
    }

    return 0;
}