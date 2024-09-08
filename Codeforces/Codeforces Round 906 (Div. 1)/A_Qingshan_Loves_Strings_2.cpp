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
        if(n%2){
            cout<<-1<<endl;
            continue;
        }

        ll c=count(all(s),'1');
        if(c!=n/2){
            cout<<-1<<endl;
            continue;
        }

        deque<ll> x;
        for(ll i=0;i<n;i++){
            x.push_back(s[i]-'0');
        }
        vector<ll> ans;
        ll p=0,q=n;
        while(!x.empty()){
            if(x.front()==x.back()){
                if(x.front()==1){
                    ans.push_back(p);
                    x.push_front(1);
                    x.push_front(0);
                    q+=2;
                }
                else{
                    ans.push_back(q);
                    x.push_back(0);
                    x.push_back(1);
                    q+=2;
                }
            }
            x.pop_back();
            x.pop_front();
            p++,q--;
        }
        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}