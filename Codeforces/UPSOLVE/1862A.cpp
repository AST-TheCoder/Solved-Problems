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
        ll n,m;
        cin>>n>>m;

        string s[n];
        for(ll i=0;i<n;i++) cin>>s[i];

        ll chk=0;
        for(ll j=0,ch='v';j<m;j++){
            ll ok=0;
            for(ll i=0;i<n;i++){
                if(ch==s[i][j]){
                    ok=1;
                    break;
                }
            }
            if(ok){
                if(ch=='v') ch='i';
                else if(ch=='i') ch='k';
                else if(ch=='k') ch='a';
                else chk=1;
            }
        }

        if(chk) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}