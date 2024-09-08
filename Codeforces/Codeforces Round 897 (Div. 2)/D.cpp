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

    read:
    while(t--){
        ll n,k;
        cin>>n>>k;


        ll a[n+1];
        for(ll i=1;i<=n;i++) cin>>a[i];

        ll chk[n+1],d=0;
        memset(chk,0,sizeof(chk));

        for(ll i=1;i<=n;i++){
            if(k==1){
                if(a[i]!=i){
                    cout<<"NO"<<endl;
                    goto read;
                }
                continue;
            }
            if(chk[i]) continue;
            d++;
            chk[i]=d;
            ll x=i;

            vector<ll> temp;
            temp.pb(i);
            ll cnt=0;
            while(1){
                ll y=a[x];
                // cout<<x<<" "<<y<<endl;
                // cnt++;
                if(cnt>50) break;
                if(!chk[y]){
                    d++;
                    chk[y]=d;
                    x=y;
                    temp.pb(x);
                    continue;
                }
                if(chk[y]==-1) break;
                if(chk[x]-chk[y]+1!=k){
                    cout<<"NO"<<endl;
                    goto read;
                }
                break;
            }

            for(ll j=0;j<temp.size();j++) chk[temp[j]]=-1;
            
        }
        cout<<"YES"<<endl;
    }

    return 0;
}