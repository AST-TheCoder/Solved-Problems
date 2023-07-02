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
        cout<<fixed<<setprecision(10);
        ll n;
        cin>>n;
        vector<double> x,y;
        cout<<"? 0 1 0"<<endl;
        for(ll i=0;i<n;i++){
            double p,q;
            cin>>p>>q;
            x.pb(p);
        }
        cout<<"? 1 0 0"<<endl;
        for(ll i=0;i<n;i++){
            double p,q;
            cin>>p>>q;
            y.pb(q);
        }

        vector<pair<double,double>> slope,ans;
        cout<<"? 1 -1 0"<<endl;
        for(ll i=0;i<n;i++){
            double p,q;
            cin>>p>>q;
            slope.pb({p,q});
        }

        for(ll i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                for(ll k=0;k<n;k++){
                    double p=(x[i]+y[j])/2;
                    double q=(x[i]+y[j])/2;
                    if((p-slope[i].second)*(p-slope[i].second)+(p-slope[i].first)*(p-slope[i].first)<0.1){
                        ans.pb({x[j],y[k]});
                        break;
                    }
                }
            }
        }
        
        cout<<"!";
        for(ll i=0;i<ans.size();i++) cout<<" "<<ans[i].first<<" "<<ans[i].second;
        cout<<endl;
    }

    return 0;
}