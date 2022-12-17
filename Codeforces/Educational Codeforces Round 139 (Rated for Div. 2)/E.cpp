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

    ll n,ans=0;
    cin>>n;

    ll a[n+1];
    for(ll i=1;i<=n;i++) cin>>a[i];

    vector<ll> b[3];
    ll p[n+1][4];
    ll s[4];

    memset(p,0,sizeof(p));
    memset(s,0,sizeof(s));

    for(ll i=1;i<=n;i++){
        if(!a[i]) ans+=i*(n-i+1);
        else if(!b[0].size() || a[b[0][b[0].size()-1]]==a[i] || a[b[0][b[0].size()-1]]==3 || a[i]==3){
            b[0].pb(i);
        }
        else if(a[i]==1) b[1].pb(i);
        else b[2].pb(i);

        for(ll j=0;j<4;j++) p[i][j]=s[j];
        s[a[i]]=i;
    }

    for(ll i=0;i<=2;i++){
        for(ll j=0;j<b[i].size();j++){
            ll prev=ans;
            if(!j) ans+=b[i][j]*(n-b[i][j]+1);
            else{
                ll cnt;
                if(a[b[i][j]]==3) cnt=b[i][j]-max(p[b[i][j]][1],max(p[b[i][j]][2],p[b[i][j]][3]));
                else if(!i) cnt=b[i][j]-b[i][j-1];
                else if(p[b[i][j]][3]<b[i][j-1]) cnt=b[i][j]-b[i][j-1];
                else if(a[b[i][j]]==2) cnt=b[i][j]-max(p[b[i][j-1]][1],p[b[i][j-1]][3]);
                else cnt=b[i][j]-max(p[b[i][j-1]][2],p[b[i][j-1]][3]);
                ans+=cnt*(n-b[i][j]+1);
            }
            cout<<i<<" "<<b[i][j]<<" "<<a[b[i][j]]<<" "<<ans-prev<<endl;
        }
    }

    cout<<ans<<endl;

    return 0;
}