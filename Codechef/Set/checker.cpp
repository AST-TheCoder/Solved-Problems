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

    freopen("out/d.in","r",stdin);
    ll n;
    cin>>n;
    fclose(stdin);
    freopen("out/d.out","r",stdin);

    vector<ll> x;
    ll temp;
    while(cin>>temp) x.pb(temp);
    if(n!=x.size()) cout<<"WA"<<endl;

    return 0;
}