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
        string x,y;
        cin>>x>>y;

        if(x==y){
            cout<<"YES"<<endl;
            continue;
        }
        if(x[0]!=y[0] || x[x.size()-1]!=y[y.size()-1]){
            cout<<"NO"<<endl;
            continue;
        }
        if(x[0]==x[x.size()-1]){
            cout<<"YES"<<endl;
            continue;
        }

        for(ll i=0;i<x.size()-1;i++){
            if(x[i]==y[i] && x[i+1]==y[i+1] && x[i]==x[0] && x[i+1]==x[x.size()-1]){
                cout<<"YES"<<endl;
                goto read;
            }
        }

        cout<<"NO"<<endl;
    }

    return 0;
}