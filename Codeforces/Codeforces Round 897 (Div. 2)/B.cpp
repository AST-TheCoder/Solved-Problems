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

        string p;
        for(ll i=0;i<=n;i++) p+='0';
        ll c=0;
        for(ll i=0,j=s.size()-1;i<j;i++,j--){
            if(s[i]!=s[j]) c++;
        }

        ll x=n;
        x-=2*c;
        for(ll i=c;i<=c+x;){
            p[i]='1';
            if(x%2) i++;
            else i+=2;
        }
        cout<<p<<endl;
    }

    return 0;
}