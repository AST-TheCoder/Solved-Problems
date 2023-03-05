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
        ll n,m;
        cin>>n>>m;

        ll ans[n+1],k=n,cnt[n+m+1];
        memset(cnt,0,sizeof(cnt));
        memset(ans,-1,sizeof(ans));

        for(ll i=1;i<=m;i++){
            ll x;
            cin>>x;

            if(cnt[x]) continue;
            cnt[x]=1;
            ans[k]=i;
            k--;
        }
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}