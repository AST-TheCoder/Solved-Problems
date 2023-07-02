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
        ll n,k;
        cin>>n>>k;

        string s="abc",ans="abc";
        ll p[k+1],c[k+1];
        p[0]=3;
        c[0]=3;
        for(ll i=1;i<=k;i++) cin>>p[i];
        for(ll i=1;i<=k;i++) cin>>c[i];

        char ch='d';
        ll j=0;
        for(ll i=1;i<=k;i++){
            if(p[i]==3 && c[i]==3) continue;
            if(p[i]-p[i-1]<c[i]-c[i-1]){
                cout<<"NO"<<endl;
                goto read;
            }
            ll d=c[i]-c[i-1];
            while(d--){
                ans+=ch;
            }
            ch++;
            while(ans.size()!=p[i]){
                ans+=s[j];
                j++;
                if(j==3) j=0;
            }
        }
        while(ans.size()!=n){
            ans+=s[j];
            j++;
        }
        cout<<"YES"<<endl;
        cout<<ans<<endl;
    }

    return 0;
}