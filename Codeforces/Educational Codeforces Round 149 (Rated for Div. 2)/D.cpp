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

        string s;
        cin>>s;

        if(count(all(s),'(')!=count(all(s),')')){
            cout<<-1<<endl;
            continue;
        }

        stack<ll> p;
        for(ll i=0;i<n;i++){
            if(s[i]=='(') p.push(i);
            else if(p.size()) p.pop();
            else{
                p.push(-1);
                break;
            }
        }
        if(!p.size()){
            cout<<1<<endl;
            for(ll i=0;i<n;i++) cout<<1<<" ";
            cout<<endl;
            continue;
        }

        stack<ll> q;
        for(ll i=0;i<n;i++){
            if(s[i]==')') q.push(i);
            else if(q.size()) q.pop();
            else{
                q.push(-1);
                break;
            }
        }
        if(!q.size()){
            cout<<1<<endl;
            for(ll i=0;i<n;i++) cout<<1<<" ";
            cout<<endl;
            continue;
        }

        ll ans[n],c=0;
        memset(ans,0,sizeof(ans));

        stack<ll> x;
        for(ll i=0;i<n;i++){
            if(s[i]==')'){
                x.push(i);
            }
            else if(x.size()){
                ans[x.top()]=1;
                ans[i]=1;
                s[x.top()]='-';
                s[i]='-';
                x.pop();
                if(c<1) c++;
            }
        }

        stack<ll> y;
        ll ok=0;
        for(ll i=0;i<n;i++){
            if(s[i]=='-') continue;
            if(s[i]=='('){
                y.push(i);
            }
            else if(y.size()){
                if(!c){
                    ans[y.top()]=1;
                    ans[i]=1;
                    ok=1;
                }
                else{
                    ans[y.top()]=2;
                    ans[i]=2;
                    ok=1;
                }
                y.pop();
            }
        }
        if(ok) c++;
        cout<<c<<endl;
        for(ll i=0;i<n;i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}