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

    ll nodes=1;
    for(ll i=1;i<=25;i++){
        nodes+=2;
        if(nodes>1e18) nodes--;
        cout<<"?"<<" "<<1<<" "<<nodes<<endl;
        ll x;
        cin>>x;
        if(x==-1){
            nodes--;
            cout<<"?"<<" "<<1<<" "<<nodes<<endl;
            cin>>x;
            if(x==-1) nodes--;
            cout<<"!"<<" "<<nodes<<endl;
            return 0;
        }
        cout<<"?"<<" "<<nodes<<" "<<1<<endl;
        ll y;
        cin>>y;
        if(x!=y){
            cout<<"!"<<" "<<x+y<<endl;
            return 0;
        }
        nodes=max(nodes+1,x+1);
    }

    cout<<"!"<<" "<<nodes<<endl;

    return 0;
}