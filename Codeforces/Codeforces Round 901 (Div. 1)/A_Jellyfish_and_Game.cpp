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
    cin>>t;

    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;

        ll a[n],b[m];
        ordered_set<ll> p,q;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            p.insert(a[i]);
        }
        for(ll j=0;j<m;j++){
            cin>>b[j];
            q.insert(b[j]);
        }

        for(ll i=0;i<=200 && k>1;i+=2,k-=2){
            ll x=*p.begin();
            ll y=*q.find_by_order(q.size()-1);
            if(x<y){
                p.erase(p.begin());
                p.insert(y);
                q.erase(q.find_by_order(q.size()-1));
                q.insert(x);
            }
            x=*q.begin();
            y=*p.find_by_order(p.size()-1);
            if(x<y){
                q.erase(q.begin());
                q.insert(y);
                p.erase(p.find_by_order(p.size()-1));
                p.insert(x);
            }
        }

        k%=2;
        ll mn=*p.begin(),x=0,mx=*q.find_by_order(q.size()-1);
        while(!p.empty()){
            x+=*p.begin();
            p.erase(p.begin());
        }

        if(k){
            if(mn<mx){
                x-=mn;
                x+=mx;
            }
        }

        cout<<x<<endl;
    }
    return 0;
}