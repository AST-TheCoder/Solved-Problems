#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 10000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

ll mem[1000001][10];

int main()
{

    for(ll i=1;i<=1000000;i++){
        for(ll j=0;j<=9;j++) mem[i][j]=mem[i-1][j];
        string s=to_string(i);
        sort(all(s));
        ll d=(ll)s[s.size()-1]-(ll)s[0];
        mem[i][d]=i;
    }
    ll t;
    cin>>t;

    read:
    while(t--){
        ll l,r;
        cin>>l>>r;
        for(ll i=9;i>=0;i--){
            if(mem[r][i]>=l){
                cout<<mem[r][i]<<"\n";
                goto read;
            }
        }
    }

    return 0;
}