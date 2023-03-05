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
        string s;
        cin>>s;

        sort(all(s));
        string a,b,ans;
        for(ll i=0;i<s.size();i+=2){
            if(i+1==s.size()){
                a+=s[i];
                reverse(all(b));
                ans=a+b;
                break;
            }
            a+=s[i+1];
            b+=s[i];

            if(a>b){
                //cout<<a<<" "<<b<<" "<<s<<endl;
                char ch='#';
                if(a[a.size()-1]==s[s.size()-1]){
                    ch=b[b.size()-1];
                    b[b.size()-1]=a[a.size()-1];
                }
                for(ll j=i+2;j<s.size();j++) a+=s[j];
                reverse(all(b));
                ans=a+b;
                if(ch!='#'){
                    ans[s.size()/2]=ch;
                }
                break;
            }
            if(i+2>=s.size()){
                reverse(all(b));
                ans=a+b;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}