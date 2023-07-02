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
        ll n;
        cin>>n;
        ll a[2][n+1];
        for(ll i=1,x=1,y=2*n;i<=n;i++){
            if(i%2){
                a[0][i]=y;
                a[1][i]=x;
            }
            else{
                a[1][i]=y;
                a[0][i]=x;
            }
            y--;
            x++;
        }
        for(ll i=2,j=n;i<j;i+=2,j-=2){
            swap(a[1][i],a[1][j]);
        }
        for(ll i=0;i<2;i++){
            for(ll j=1;j<=n;j++) cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }

    return 0;
}