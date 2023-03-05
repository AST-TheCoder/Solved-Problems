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
        vector<pair<ll,ll>> temp;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            temp.pb({a[i],i});
        }
        sort(all(temp));

        ll val=0,len=0;
        for(ll i=0;i<n;i++){
            if(temp[i].first!=val) len++;
            val=temp[i].first;
            a[temp[i].second]=len;
        }

        vector<ll> idx[len+1];
        for(ll i=0;i<n;i++){
            idx[a[i]].pb(i);
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            ll chk[len+1];
            memset(chk,0,sizeof(chk));

            ll d=n-i;
            d=(d*(d+1))/2;
            set<ll> seg;
            seg.insert(i);
            seg.insert(n);
            for(ll j=i;j<n;j++){
                seg.erase(seg.begin());
                ll p=*seg.begin();
                seg.insert(j);
                d-=(p-j);
                //cout<<i<<" "<<j<<" "<<ans<<endl;
                if(chk[a[j]]){
                    ans+=d;
                    continue;
                }
                chk[a[j]]=1;

                for(ll k=0;k<idx[a[j]].size();k++){
                    ll id=idx[a[j]][k];
                    if(id<=j) continue;
                    set<ll>::iterator it=seg.upper_bound(id);
                    ll r=*it;
                    it--;
                    ll l=*it;
                    ll x=r-l-1;
                    d-=(x*(x+1))/2;
                    x=id-l-1;
                    d+=(x*(x+1))/2;
                    x=r-id-1;
                    d+=(x*(x+1))/2;
                    seg.insert(id);
                }
                ans+=d;
                //cout<<i<<" "<<j<<" "<<d<<" "<<ans<<endl;
            }
        }
        cout<<ans<<endl;

    }

    return 0;
}