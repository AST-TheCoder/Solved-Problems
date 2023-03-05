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

    vector<pair<ll,string>> v;
    for(ll i=0;i<n;i++){
        ll x;
        string p;
        cin>>p>>x;
        v.pb({x,p});
    }
    sort(all(v));
    cout<<"Selise Coding Challenge 2023 Winners\n";
    cout<<"Winner: "<<v[0].second<<" => "<<v[0].first<<endl;
    cout<<"1st Runner Up: "<<v[1].second<<" => "<<v[1].first<<endl;
    cout<<"2nd Runner Up: "<<v[2].second<<" => "<<v[2].first<<endl;

    return 0;
}