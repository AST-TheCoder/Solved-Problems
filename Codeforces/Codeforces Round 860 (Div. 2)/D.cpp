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

        priority_queue<ll> a,b;
        ll s=0,mx=-Max,mn=Max,pos=0,neg=0;
        for(ll i=0;i<n;i++){
            ll x;
            cin>>x;
            s+=x;
            mx=max(mx,x);
            mn=min(mn,x);
            if(x>=0){
                a.push(x);
                pos+=x;
            }
            else{
                b.push(-x);
                neg-=x;
            }
        }
        if(mx-mn<=s){
            cout<<"NO\n";
            continue;
        }
        ll d=mx-mn;
        cout<<"YES\n";
        ll psum=0,nsum=0;
        for(ll i=0;i<n;i++){
            if(d-psum<=a.top()){
                cout<<-b.top()<<" ";
                psum-=b.top();
                nsum+=b.top();
                neg-=b.top();
                b.pop();
                if(psum<0) psum=0;
            }
            else if(d-nsum<=b.top()){
                cout<<a.top()<<" ";
                nsum-=a.top();
                psum+=a.top();
                pos-=a.top();
                a.pop();
                if(nsum<0) nsum=0;
            }
            else if(pos>=neg){
                cout<<a.top()<<" ";
                nsum-=a.top();
                psum+=a.top();
                pos-=a.top();
                a.pop();
                if(nsum<0) nsum=0;
            }
            else{
                cout<<-b.top()<<" ";
                psum-=b.top();
                nsum+=b.top();
                neg-=b.top();
                b.pop();
                if(psum<0) psum=0;
            }
        }
        cout<<endl;
    }

    return 0;
}