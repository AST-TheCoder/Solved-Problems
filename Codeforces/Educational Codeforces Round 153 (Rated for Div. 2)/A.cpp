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

        if(s=="()"){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
        ll c=0;
        for(ll i=1;i<s.size();i++) if(s[i]==s[i-1]) c++;
        if(c){
            for(ll i=0;i<s.size();i++) cout<<"()";
            cout<<endl;
        }
        else{
            for(ll i=0;i<s.size();i++) cout<<"(";
            for(ll i=0;i<s.size();i++) cout<<")";
            cout<<endl;
        }
    }

    return 0;
}