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

        ll a[n];
        priority_queue<ll> p;
        min_heap<ll> q;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            p.push(a[i]);
            q.push(a[i]);
        }

        for(ll i=0,j=n-1;i<j;){
            if(j-i+1<4) break;
            if(a[i]==p.top() || a[j]==p.top()){
                if(a[i]==p.top()) i++;
                else j--;
                p.pop();
                continue;
            }
            if(a[i]==q.top() || a[j]==q.top()){
                if(a[i]==q.top()) i++;
                else j--;
                q.pop();
                continue;
            }
            cout<<i+1<<" "<<j+1<<endl;
            goto read;
        }
        cout<<-1<<endl;
    }

    return 0;
}