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

    string s;
    cin>>s;
    ll n;
    cin>>n;
    vector<vector<ll>> x;
    for(ll i=0;i<n;i++){
        string temp,ch;
        cin>>temp>>ch;
        if(ch=="+") continue;
        vector<ll> p;
        for(ll j=0;j<48;j++) if(temp[j]!=s[j]) p.pb(j);
        if(p.size()==3) x.pb(p);   
    }
    for(ll i=0;i<x.size();i++){
        for(ll j=0;j<x.size();j++){
            set<ll> ans;
            for(ll k=0;k<3;k++) ans.insert(x[i][k]);
            for(ll k=0;k<3;k++) ans.insert(x[j][k]);
            if(ans.size()==6){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;

    return 0;
}