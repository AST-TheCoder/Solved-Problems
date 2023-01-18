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

    read:

    while(t--){
        string s;
        cin>>s;
        ll n=s.size();

        string a,b,c;

        a+=s[0];
        b+=s[1];
        for(ll i=2;i<n;i++) c+=s[i];
        if((b<=a && b<=c) || (b>=a && b>=c)){
            cout<<a<<" "<<b<<" "<<c<<endl;
            continue;
        }

        a.clear();
        b.clear();
        c.clear();
        a+=s[0];
        for(ll i=1;i<n-1;i++) b+=s[i];
        c+=s[n-1];
        if((b<=a && b<=c) || (b>=a && b>=c)){
            cout<<a<<" "<<b<<" "<<c<<endl;
            continue;
        }

        a.clear();
        b.clear();
        c.clear();
        for(ll i=0;i<n-2;i++) a+=s[i];
        b+=s[n-2];
        c+=s[n-1];
        if((b<=a && b<=c) || (b>=a && b>=c)){
            cout<<a<<" "<<b<<" "<<c<<endl;
            continue;
        }

        cout<<":("<<endl;
    }

    return 0;
}