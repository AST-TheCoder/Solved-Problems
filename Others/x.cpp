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

const int mod = 1e9+7;

int main()
{
    ll n,k; cin>>n>>k;
    ll a[n];
    ll l50=0,l100=0,r50=0,r100=0;
    for(ll i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==50) l50++;
        else l100++;
    }
    //cout<<l50<<' '<<l100<<endl;
    sort(a,a+n);
    if(n==1){
        if(a[0]<=k) cout<<1<<endl<<1<<endl;
        else cout<<-1<<endl<<0<<endl;
        return 0;
    }
    if(a[n-1]>k || a[0]+a[1]>k){
        cout<<-1<<endl<<0<<endl;
        return 0;
    }

    ll ways=1,times=0;
    for(ll i=0; ;i++){
        if(!l50 && !l100) break;
        times++;
        if(i%2==0 && (l50>1 || k>=150)){
            ll sum=0;
            while(l50 && sum+50<=k){
                sum+=50; l50--; r50++;
            }
            while(l100 && sum+100<=k){
                sum+=100; l100--; r100++;
            }
            if(!l50 && !l100) break;
        }
        else if(i%2==0){
            ll sum=0;
            while(l100 && sum+100<=k){
                sum+=100; l100--; r100++;
            }
            while(l50 && sum+50<=k){
                sum+=50; l50--; r50++;
            }
            if(!l50 && !l100) break;
        }
        else{
            if(r50){
                ways=(ways*r50)%mod;;
                l50++; r50--;
            }
            else{
                ways=(ways*r100)%mod;
                l100++; r100--;
            }
        }
        // cout<<l50<<' '<<l100<<' '<<r50<<' '<<r100<<endl;
        // cout<<times<<' '<<ways<<endl;
        // if(times==5) break;
    }

    cout<<times<<endl<<ways<<endl;

    
    
    

    return 0;
}