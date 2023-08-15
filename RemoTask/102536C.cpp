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
        double g;
        cin>>n>>g;
        double w=0.0;
        for(ll i=0;i<n;i++){
            double temp;
            cin>>temp;
            w+=temp*temp;
        }

        double m=0.0,c=0.0;
        for(ll i=0;i<n;i++){
            double x,y;
            cin>>x>>y;
            m+=x,c+=y;
        }

        double ans;
        if(c<=0.0) ans=0.0;
        else if(m>0) ans=c*(sqrtl(w)*g+m)/(w*g*g-m*m);
        else ans=c/(sqrtl(w)*g-m);

        cout<<fixed<<setprecision(12)<<ans<<endl;
    }

    return 0;
}