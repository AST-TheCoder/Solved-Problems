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

    read:
    while(t--){

        ll n;
        cin>>n;
        string s;
        cin>>s;

        if(n<=3){
            cout<<"NO"<<endl;
            goto read;
        }

        ll p[26][26];
        memset(p,0,sizeof(p));
        p[s[0]-'a'][s[1]-'a']=1;

        for(ll i=3;i<n;i++){
            if(p[s[i-1]-'a'][s[i]-'a']){
                cout<<"YES"<<endl;
                goto read;
            }
            p[s[i-2]-'a'][s[i-1]-'a']=1;
        }
        cout<<"NO"<<endl;
    }

    return 0;
}