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

        string s[n+1];
        for(ll i=1;i<=n;i++) cin>>s[i];

        map<string,vector<ll>> m;

        for(ll i=1;i<=n;i++){
            ll x=count(all(s[i]),'w');
            ll y=count(all(s[i]),'i');
            ll z=count(all(s[i]),'n');

            if(x>1 && !y) m["wi"].pb(i);
            if(x>1 && !z) m["wn"].pb(i);
            if(y>1 && !x) m["iw"].pb(i);
            if(y>1 && !z) m["in"].pb(i);
            if(z>1 && !x) m["nw"].pb(i);
            if(z>1 && !y) m["ni"].pb(i);
        }

        vector<pair<pair<ll,char>,pair<ll,char>>> ans;

        for(ll i=(ll)m["wi"].size()-1,j=(ll)m["iw"].size()-1; i>=0 && j>=0;i--,j--){
            ans.pb({{m["wi"][i],'w'},{m["iw"][j],'i'}});
            m["wi"].pop_back();
            m["iw"].pop_back();
        }
        for(ll i=(ll)m["wn"].size()-1,j=(ll)m["nw"].size()-1; i>=0 && j>=0;i--,j--){
            ans.pb({{m["wn"][i],'w'},{m["nw"][j],'n'}});
            m["wn"].pop_back();
            m["nw"].pop_back();
        }
        for(ll i=(ll)m["in"].size()-1,j=(ll)m["ni"].size()-1; i>=0 && j>=0;i--,j--){
            ans.pb({{m["in"][i],'i'},{m["ni"][j],'n'}});
            m["in"].pop_back();
            m["ni"].pop_back();
        }
        for(ll i=0;i<m["wi"].size();i++){
            ll x=m["wi"][i];
            ll y=m["in"][i];
            ll z=m["nw"][i];

            ans.pb({{x,'w'},{y,'i'}});
            ans.pb({{y,'w'},{z,'n'}});
        }
        for(ll i=0;i<m["iw"].size();i++){
            ll x=m["wn"][i];
            ll y=m["ni"][i];
            ll z=m["iw"][i];

            ans.pb({{x,'w'},{y,'n'}});
            ans.pb({{y,'w'},{z,'i'}});
        }
        cout<<ans.size()<<"\n";
        for(ll i=0;i<ans.size();i++){
            cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<"\n";
        }
    }

    return 0;
}