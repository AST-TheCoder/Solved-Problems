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
        string s;
        cin>>s;

        sort(all(s));

        ll mx=1,c=1;
        for(ll i=1;i<4;i++){
            if(s[i]!=s[i-1]){
                mx=max(mx,c);
                c=1;
            }
            else c++;
        }
        mx=max(mx,c);
        if(mx==4) cout<<-1<<endl;
        else if(mx==3) cout<<6<<endl;
        else cout<<4<<endl;
    }

    return 0;
}