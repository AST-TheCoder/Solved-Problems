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

    ll n,k;
    cin>>n>>k;

    ll a[n+1],v=k;
    for(ll i=1;i<=n;i++) cin>>a[i];
    vector<pair<ll,ll>> ans;
    ll s=0;
    for(ll i=1,j=1;i<=n;i++){
        if(k==1){
            k--;
            ans.pb({j,n});
            ll x=count(a+i,a+n+1,0);
            if(x && x!=n-i+1) s=1;
            break;
        }
        if(i!=1 && a[i]!=a[i-1]){
            k--;
            ans.pb({j,i-1});
            j=i;
        }
        if(i==n){
            k--;
            ans.pb({j,n});
        }
    }

    if(s){
        cout<<s<<endl;
        for(ll i=1;i<=n;i++){
            if(v==1){
                cout<<i<<" "<<n<<endl;
                break;
            }
            cout<<i<<" "<<i<<endl;
            v--;
        }
        return 0;
    }

    for(ll i=0;i<ans.size() && k;i++){
        if(ans[i].first==ans[i].second) continue;
        ans.pb({ans[i].first,ans[i].first});
        ans[i].first++;
        k--;
        i--;
    }
    sort(all(ans));
    cout<<s<<endl;
    for(ll i=0;i<ans.size();i++) cout<<ans[i].first<<" "<<ans[i].second<<endl;

    return 0;
}