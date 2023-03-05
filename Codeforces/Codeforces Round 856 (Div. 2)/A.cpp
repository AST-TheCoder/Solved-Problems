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
        vector<string> x;
        for(ll i=0;i<2*n-2;i++){
            string p;
            cin>>p;

            if(p.size()==n-1) x.pb(p);
        }

        string s;
        string chk1,chk2;
        for(ll i=0;i<n-2;i++){
            chk1+=x[0][i];
            chk2+=x[1][i+1];
        }
        if(chk1==chk2){
            s=x[1];
            s+=x[0][n-2];
        }
        else{
            s=x[0];
            s+=x[1][n-2];
        }

        ll ok=0;
        for(ll i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                ok=1;
                break;
            }
        }
        //cout<<s<<" "<<x[0]<<" "<<x[1]<<" "<<chk1<<" "<<chk2<<endl;
        if(ok) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

    return 0;
}