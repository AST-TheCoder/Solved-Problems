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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

int main()
{

    ll t;
    scanf("%lli",&t);

    while(t--){
        ll n;
        scanf("%lli",&n);

        ll a[n];
        ordered_set<ll> s;
        for(ll i=0;i<n;i++){
            scanf("%lli",&a[i]);
            s.insert(a[i]);
        }

        vector<ll> d[n];
        sort(a,a+n);
        for(ll i=0;i<n;i++){
            if(i && a[i]==a[i-1]){
                d[i]=d[i-1];
                continue;
            }
            for(ll j=1;j*j*j<=a[i];j++){
                if(a[i]%(j*j)==0) d[i].pb(j);
                if(a[i]%j) continue;
                ll v=a[i]/j;
                ll p=sqrt(v);
                if(p*p==v) d[i].pb(p);
            }
            sort(all(d[i]));
        }
        ll ans=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<d[i].size();j++){
                if(j && d[i][j]==d[i][j-1]) continue;
                ll x=d[i][j];
                if(x==1){
                    ll cnt=s.order_of_key(a[i]+1)-s.order_of_key(a[i]);
                    //cout<<a[i]<<" "<<cnt<<endl;
                    ans+=((cnt-1)*(cnt-2));
                    continue;
                }
                ll p=a[i]/x;
                ll q=p/x;
                p=s.order_of_key(p+1)-s.order_of_key(p);
                q=s.order_of_key(q+1)-s.order_of_key(q);
                ans+=(p*q);
            }
        }
        printf("%lli\n",ans);
    }

    return 0;
}