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
        a[0]=0;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        for(ll i=1,prev=-1;i<=n;i++){
            if(a[i]<=0 || prev>0){
                if(a[i]) prev=a[i];
                continue;
            }
            ll temp[n+1];
            for(ll j=1;j<=n;j++) temp[j]=a[j];
            vector<pair<ll,ll>> ans;
            for(ll j=i-1;j>1;j--){
                if(temp[j-1]>temp[j]){
                    if(temp[j-1]>0){
                        while(abs(temp[j])<temp[j-1]){
                            ans.pb({j,j});
                            temp[j]+=temp[j];
                        }
                        temp[j-1]+=temp[j];
                        ans.pb({j-1,j});
                    }
                    temp[j-1]+=temp[j];
                    ans.pb({j-1,j});
                }
            }
            for(ll j=i+1;j<=n;j++){
                if(temp[j]<temp[j-1]){
                    if(temp[j]<0){
                        while(temp[j-1]<abs(temp[j])){
                            ans.pb({j-1,j-1});
                            temp[j-1]+=temp[j-1];
                        }
                        temp[j]+=temp[j-1];
                        ans.pb({j,j-1});
                    }
                    temp[j]+=temp[j-1];
                    ans.pb({j,j-1});
                }
            }
            if(ans.size()>31) continue;
            //cout<<"Case "<<t+1<<" ";
            cout<<ans.size()<<endl;
            for(ll j=0;j<ans.size();j++) cout<<ans[j].first<<" "<<ans[j].second<<endl;
            goto read;
        }

        ll temp[n+1];
        for(ll j=1;j<=n;j++) temp[j]=a[j];
        vector<pair<ll,ll>> ans;
        for(ll j=n;j>1;j--){
            if(temp[j-1]>temp[j]){
                if(temp[j-1]>0){
                    while(abs(temp[j])<temp[j-1]){
                        ans.pb({j,j});
                        temp[j]+=temp[j];
                    }
                    temp[j-1]+=temp[j];
                    ans.pb({j-1,j});
                }
                temp[j-1]+=temp[j];
                ans.pb({j-1,j});
            }
        }
        //cout<<"Case "<<t+1<<" ";
        cout<<ans.size()<<endl;
        for(ll j=0;j<ans.size();j++) cout<<ans[j].first<<" "<<ans[j].second<<endl;
    }

    return 0;
}