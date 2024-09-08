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

        reverse(all(s));
        vector<ll> x;
        for(ll i=0,c=0;i<n;i++){
            if(s[i]=='0'){
                x.pb(i-c);
                c++;
            }
        }
        for(ll i=1,s=0;i<=n;i++){
            if(i>x.size()) cout<<-1<<" ";
            else{
                s+=x[i-1];
                cout<<s<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}