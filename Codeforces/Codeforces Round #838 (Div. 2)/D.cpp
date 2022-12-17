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

        vector<ll> temp;
        for(ll i=1;i<=n;i++) temp.pb(i);

        while(temp.size()!=2){
            ll id=temp[0],mx=-1;
            vector<ll> chk,agn;
            chk.pb(-1);
            for(ll i=1;i<temp.size();i++){
                ll x;
                cout<<"? "<<id<<" "<<temp[i]<<endl;
                cin>>x;
                if(x==-1) return 0;

                mx=max(mx,x);
                chk.pb(x);

            }

            for(ll i=1;i<temp.size();i++){
                if(chk[i]==mx){
                    agn.pb(temp[i]);
                }
            }
            temp=agn;
            if(temp.size()==1) temp.pb(id);
        }

        ll x;
        cout<<"! "<<temp[0]<<" "<<temp[1]<<endl;
        cin>>x;

        if(x==-1) return 0;

    }

    return 0;
}