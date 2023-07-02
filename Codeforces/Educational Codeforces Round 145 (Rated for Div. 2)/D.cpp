#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 1000000000000000000

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

        ll o[s.size()],z[s.size()];
        memset(o,0,sizeof(o));
        memset(z,0,sizeof(z));

        for(ll i=0,c=0;i<s.size();i++){
            o[i]=c;
            if(s[i]=='1') c++;
        }
        for(ll i=s.size()-1,c=0;i>=0;i--){
            z[i]=c;
            if(s[i]=='0') c++;
        }
        ll ans=Max;
        for(ll i=0;i<s.size();i++){
            ll temp=(1e12+1)*(o[i]+z[i]);
            if(s[i]=='1' && i+1!=s.size() && s[i+1]=='0') temp--;
            if(s[i]=='0' && i && s[i-1]=='1') temp--;

            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }

    return 0;
}