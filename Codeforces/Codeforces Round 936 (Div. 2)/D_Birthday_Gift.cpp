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
        ll n, val;
        cin>>n>>val;
        ll a[n], temp=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            temp^=a[i];
        }
        if(temp>val){
            cout<<-1<<endl;
            continue;
        }
        ll ans=1;
        for(ll i=0;i<=30;i++){
            ll temp_or=0, temp_ans=0;
            for(ll j=0, temp_xor=0;j<n;j++){
                temp_xor^=a[j];
                if(((temp_xor>>i)|(val>>i))==(val>>i)){
                    //cout<<i<<" "<<temp_xor<<" "<<(temp_xor>>i)<<endl;
                    temp_or|=temp_xor;
                    temp_xor=0;
                    temp_ans++;
                }
                if(j+1==n && !temp_xor && temp_or<=val)
                    ans=max(ans, temp_ans);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}