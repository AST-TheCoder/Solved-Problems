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
        ll n;
        cin>>n;

        ll a[n+1];
        ll x[n+1];
        ll y[n+1];
        ll chk[n+1];
        for(ll i=1;i<=n;i++){
            cin>>a[i];
            chk[i]=x[i]=y[i]=0;
        }

        for(ll i=1;i<=n;i++){
            if(!chk[a[i]]){
                chk[a[i]]=1;
                x[i]=a[i];
            }
        }
        set<ll> s;
        for(ll i=1;i<=n;i++) if(!chk[i]) s.insert(i);
        for(ll i=1;i<=n;i++){
            if(!x[i]){
                set<ll>::iterator it=s.lower_bound(a[i]);
                if(it==s.begin()){
                    cout<<"NO"<<endl;
                    goto read;
                }
                it--;
                x[i]=*it;
                s.erase(it);
            }
            chk[i]=0;
        }

        for(ll i=1;i<=n;i++){
            if(x[i]!=a[i]){
                if(chk[a[i]]){
                    cout<<"NO"<<endl;
                    goto read;
                }
                y[i]=a[i];
                chk[a[i]]=1;
            }
        }
        for(ll i=1;i<=n;i++) if(!chk[i]) s.insert(i);
        for(ll i=1;i<=n;i++){
            if(!y[i]){
                set<ll>::iterator it=s.upper_bound(a[i]);
                if(it==s.begin()){
                    cout<<"NO"<<endl;
                    goto read;
                }
                it--;
                y[i]=*it;
                s.erase(it);
            }
        }

        cout<<"YES"<<endl;
        for(ll i=1;i<=n;i++) cout<<x[i]<<" ";cout<<endl;
        for(ll i=1;i<=n;i++) cout<<y[i]<<" ";cout<<endl;

    }

    return 0;
}