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

    ll n;
    cin>>n;

    string s;
    cin>>s;

    ll o=0,z=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='1') o++;
        else z++;
    }

    o=ceil(pow(2,o));
    z=ceil(pow(2,z))-1;
    n=ceil(pow(2,n));
    for(ll i=o;i<=n-z;i++) cout<<i<<" ";
    cout<<endl;

    return 0;
}