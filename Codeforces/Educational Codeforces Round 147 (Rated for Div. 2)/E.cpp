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
        ll k;
        cin>>k;
        string s;
        cin>>s;

        ll pos[s.size()];
        memset(pos,-1,sizeof(pos));

        stack<ll> q;
        vector<ll> v;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='(') q.push(i);
            else{
                ll x=q.top();
                q.pop();
                pos[i]=x;
                v.pb(i-x-1);
            }
        }
        sort(all(v));
        while(k--){
            if(v.size()) v.pop_back();
        }
        ll ans=0;
        for(ll i=0;i<v.size();i++) ans+=v[i]/2;
        cout<<ans<<endl;
    }

    return 0;
}