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
        pair<ll,ll> p[n+1]; 
        ll ans[n+1];
        for(ll i=1;i<=n;i++){
            ans[i]=Max;
            cin>>p[i].first;
            p[i].second=i;
        }
        sort(p+1,p+n+1,greater<pair<ll,ll>>());
        
        if(p[1].first==n && p[n].first==0){
            cout<<"NO"<<endl;
            goto read;
        }

        ll x=n;
        for(ll i=0,j=n;i<j;){
            if(x<=0){
                cout<<"NO"<<endl;
                goto read;
            }
            while(j>i && p[j].first==i){
                ans[p[j].second]=-x;
                x--;
                j--;
            }
            if(i==j) break;
            i++;
            if(x<=0){
                cout<<"NO"<<endl;
                goto read;
            }
            ll temp=x+i-1;
            if(temp!=p[i].first){
                cout<<"NO"<<endl;
                goto read;
            }
            ans[p[i].second]=x;
            x--;
        }
        if(x<0){
            cout<<"NO"<<endl;
            goto read;
        }

        cout<<"YES"<<endl;
        for(ll i=1;i<=n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}