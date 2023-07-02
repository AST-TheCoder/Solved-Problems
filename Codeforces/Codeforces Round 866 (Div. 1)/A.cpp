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

        ll a[n],b[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        ll mex=0;
        sort(b,b+n);
        for(ll i=0;i<n;i++){
            if(b[i]==mex) mex++;
            else if(b[i]>mex) break;
        }

        ll beg=-1,en=-1;
        for(ll i=0;i<n;i++){if(a[i]==mex+1){beg=i;break;}}
        for(ll i=n-1;i>=0;i--){if(a[i]==mex+1){en=i;break;}}
        //cout<<mex<<" "<<beg<<" "<<en<<endl;
        if(beg==-1){
            for(ll i=0;i<n;i++){
                if(b[i]>mex){
                    b[i]=mex;
                    break;
                }
                else if(i && b[i]==b[i-1]){
                    b[i]=mex;
                    break;
                }
            }
        }
        else{
            for(ll i=0;i<n;i++){
                if(i>=beg && i<=en) a[i]=mex;
                //cout<<a[i]<<" ";
                b[i]=a[i];
            }
            //cout<<endl;
        }

        sort(b,b+n);
        ll temp=0;
        for(ll i=0;i<n;i++){
            if(b[i]==temp) temp++;
            else if(b[i]>temp) break;
        }
        //cout<<temp<<endl;

        if(temp==mex+1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}