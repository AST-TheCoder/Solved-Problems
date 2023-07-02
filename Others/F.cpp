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

    ll n, x1, x2; cin >> n >> x1 >> x2;
    vector <pair<ll, ll>> vp;
    for(int i = 0; i < n; i++) {
        ll m, c;cin >> m >> c;
        ll y1 = m*x1+c, y2 = m*x2+c;
        vp.push_back({y1, y2});
    }
    sort(vp.rbegin(), vp.rend());
    for(int i = 1; i < n; i++) {
        if(vp[i].second > vp[i-1].second) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    
    return 0;
}