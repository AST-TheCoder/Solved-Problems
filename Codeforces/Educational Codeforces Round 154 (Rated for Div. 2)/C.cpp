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
        string s;
        cin>>s;

        ll f=0,x=0;
        stack<ll> q;
        for(ll i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(f) continue;
                if(x==q.size() || q.size()==1){
                    //cout<<i<<endl;
                    cout<<"NO"<<endl;
                    goto read;
                }
                q.pop();
                q.push(-1);
                f=1;
            }
            if(s[i]=='1'){
                if(f){
                    //cout<<i<<endl;
                    cout<<"NO"<<endl;
                    goto read;
                }
                x=q.size();
            }
            if(s[i]=='+') q.push(1);
            if(s[i]=='-'){
                if(q.top()==-1) f=0;
                //cout<<i<<" "<<q.top()<<endl;
                q.pop();
                if(x>q.size()) x=q.size();
            }
        }

        cout<<"YES"<<endl;
    }

    return 0;
}