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
        
        ll cnt[1030];
        memset(cnt,0,sizeof(cnt));

        ll n;
        cin>>n;

        for(ll i=0;i<n;i++){
            string s,p;
            cin>>s;
            sort(all(s));
            p=s[0];
            for(ll j=1;j<s.size();j++){
                if(s[j]!=s[j-1]) p+=s[j];
            }
            ll mask=0;
            for(ll j=0;j<p.size();j++){
                ll temp=p[j]-'0';
                mask|=(1LL<<temp);
            }
            cnt[mask]++;
        }

        ll ans=0;
        for(ll i=1;i<(1<<10);i++){
            ll c=0,o=__builtin_popcount(i);
            for(ll j=0;j<(1<<10);j++){
                if((i&j)!=i) continue;
                c+=cnt[j];
            }
            if(o%2) ans+=(c*(c-1))/2;
            else ans-=(c*(c-1))/2;
        }
        cout<<ans<<endl;
    }

    return 0;
}