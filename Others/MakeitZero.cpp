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
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll ans=6;
        for(ll j=0;j<=42;j++){
            for(ll k=0;k<=42;k++){
                for(ll l=0;l<=42;l++){
                    ll chk[43];
                    memset(chk,0,sizeof(chk));
                    for(ll i=0;i<n;i++){
                        ll val=a[i];
                        if(val>=j) val-=j;
                        if(val>=k) val-=k;
                        if(val>=l) val-=l;
                        chk[val]=1;
                    }
                    vector<ll> temp;
                    for(ll i=1;i<=42;i++){
                        if(chk[i]) temp.pb(i);
                    }
                    ll res=(j!=0)+(k!=0)+(l!=0);
                    if(temp.size()==1) res++;
                    else if(temp.size()==2) res+=2;
                    else if(temp.size()==3){
                        sort(all(temp));
                        if(temp[0]+temp[1]==temp[2]) res+=2;
                        else continue;
                    }
                    else if(temp.size()) continue;
                    ans=min(ans,res);
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}