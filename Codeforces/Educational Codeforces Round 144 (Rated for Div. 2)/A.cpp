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
        string chk;
        for(ll i=1;i<=100;i++){
            if(i%3==0) chk+='F';
            if(i%5==0) chk+='B';
        }
        ll ok=0;
        for(ll i=0;i<chk.size();i++){
            for(ll j=0,k=i;j<s.size() && k<chk.size();j++,k++){
                if(s[j]!=chk[k]) break;
                if(j+1==s.size()) ok=1;
            }
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}