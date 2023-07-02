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

        ll a[n];
        for(ll i=0;i<n;i++) cin>>a[i];

        string s="1";
        for(ll i=1,chk=0;i<n;i++){
            if(!chk){
                if(a[i]>=a[i-1]) s+='1';
                else{
                    if(a[i]<=a[0]){
                        s+='1';
                        chk=1;
                    }
                    else{
                        s+='0';
                        a[i]=a[i-1];
                    }
                }
            }
            else{
                if(a[i]<a[i-1]){
                    s+='0';
                    a[i]=a[i-1];
                }
                else{
                    if(a[i]<=a[0]) s+='1';
                    else{
                        s+='0';
                        a[i]=a[i-1];
                    }
                }
            }
        }
        cout<<s<<endl;
    }

    return 0;
}