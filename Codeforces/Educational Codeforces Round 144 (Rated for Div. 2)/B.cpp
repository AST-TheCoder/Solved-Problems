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
        string a,b;
        cin>>a>>b;
        if(a[0]==b[0]){
            cout<<"YES"<<endl;
            cout<<a[0]<<"*"<<endl;
            continue;
        }
        if(a[a.size()-1]==b[b.size()-1]){
            cout<<"YES"<<endl;
            cout<<"*"<<a[a.size()-1]<<endl;
            continue;
        }
        for(ll i=0;i<a.size()-1;i++){
            for(ll j=0;j<b.size()-1;j++){
                if(a[i]==b[j] && a[i+1]==b[j+1]){
                    cout<<"YES"<<endl;
                    cout<<"*"<<a[i]<<a[i+1]<<"*"<<endl;
                    goto read;
                }
            }
        }
        cout<<"NO"<<endl;
    }

    return 0;
}