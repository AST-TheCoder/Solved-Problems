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
        ll n,mod=998244353;
        cin>>n;


        string s;
        cin>>s;

        ll chk=s[0]-'0',ans=1,temp=1;

        for(ll i=1;i<n;i++){
            if(chk==s[i]-'0'){
                temp=(temp*2)%mod;
                ans=(ans+temp)%mod;
            }
            else{
                temp=1;
                chk=s[i]-'0';
                ans=(ans+temp)%mod;
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}