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
    while(cin>>s){
        ll n=s.size();
        ll ans=0;
        for(ll i=(n+1)/2;i<n;i++){
            ll x=s[n-i-1]-'a';
            ll y=s[i]-'a';
            y=(y+ans)%26;
            //cout<<i<<" "<<s[n-i-1]<<" "<<x<<" "<<s[i]<<" "<<y<<endl;
            ll m;
            if(x>=y) m=x-y;
            else m=x+26-y;
            ans+=m;
        }
        cout<<ans<<endl;
    }

    return 0;
}