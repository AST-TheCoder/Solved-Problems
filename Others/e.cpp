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

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        ll a[m];
        memset(a,0,sizeof(a));

        for(ll i=0;i<m;i++){
            ll k;
            cin>>k;

            for(ll j=0;j<k;j++){
                ll x;
                cin>>x;

                a[i]|=(1LL<<x);
            }
        }

        map<ll,ll> mp;
        set<ll> chk;

        for(ll i=0;i<(1LL<<m);i++){
            ll cnt=0,val=0;
            for(ll j=0;j<n;j++){
                if(i&(1LL<<j)){
                    cnt++;
                    val^=a[j];
                }
            }
            ll sz=chk.size();
            chk.insert(val);
            if(sz==chk.size()) mp[val]=min(mp[val],cnt);
            else mp[val]=cnt;
            //cout<<val<<endl;
        }

        ll q;
        cin>>q;
        cout<<"Case "<<++ii<<":"<<endl;
        while(q--){
            string s;
            cin>>s;

            ll val=0;
            for(ll i=n-1,j=0;i>=0;i--,j++){
                if(s[i]=='1') val|=(1LL<<j);
            }
            //cout<<val<<endl;
            if(mp[val]!=0) cout<<mp[val]<<endl;
            else cout<<-1<<endl;
        }
        cout<<endl;
    }

    return 0;
}