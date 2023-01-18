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

        ll c[2*n+1];
        memset(c,0,sizeof(c));

        ll x=0,ans=(n*(n+1))/2;
        c[0]=1;
        for(ll i=0;i<n;i++){
            ll v;
            cin>>v;

            x^=v;
            ans-=c[x];
            c[x]++;
            for(ll j=1;j<=700;j++){
                ll chk=j*j;
                if(chk>2*n) break;
                //cout<<x<<" "<<chk<<" ";
                chk=x^chk;
                //cout<<chk<<endl;
                if(chk>2*n) continue;
                ans-=c[chk];
            }
        }

        cout<<ans<<"\n";
    }

    return 0;
}