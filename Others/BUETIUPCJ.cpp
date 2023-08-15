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

ll phi[501];

int main()
{

    for(ll i=1;i<=500;i++) phi[i]=i;
    for(ll i=1;i<=500;i++){
        for(ll j=2*i;j<=500;j+=i) phi[j]-=phi[i];
        ll cnt=0,j=i;
        while(j!=1){
            cnt++;
            j=phi[j];
        }
        cout<<i<<" "<<phi[i]<<" "<<cnt<<endl;
    }

    return 0;
}