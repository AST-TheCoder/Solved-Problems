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

        ll pos[n+m+1],cnt[n+m+1],a[n+1];
        memset(pos,-1,sizeof(pos));
        memset(cnt,0,sizeof(cnt));

        for(ll i=1;i<=n;i++){
            cin>>a[i];
            pos[a[i]]=0;
        }

        for(ll i=1;i<=m;i++){
            ll p,v;
            cin>>p>>v;

            ll val=a[p];
            //cout<<i<<" "<<p<<" "<<v<<" "<<val<<endl;
            cnt[val]+=(i-pos[val]);
            pos[val]=-1;
            a[p]=v;
            pos[v]=i;
        }
        for(ll i=1;i<=n+m;i++){
            if(pos[i]!=-1) cnt[i]+=(m-pos[i]+1);
            //cout<<i<<" "<<cnt[i]<<endl;
        }

        ll temp[m+2];
        temp[0]=0;
        for(ll i=1,j=m;i<=m+1;i++){
            temp[i]=j;
            j+=m-i;
        }

        ll ans=0;
        for(ll i=1;i<=n+m;i++) ans+=temp[cnt[i]];
        cout<<ans<<endl;

    }

    return 0;
}