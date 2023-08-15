#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define pb push_back
#define all(x) x.begin(),x.end()
#define Max 1000000000000000000

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using min_heap=priority_queue<T, vector<T>, greater<T>>;

int main()
{    
    ll t;
    cin>>t;
    read:  
    while (t--) {
        int n;
        cin>>n;
        vector<ll> a(n),b(n+1),c(n+1);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        if(n==1){
            cout<<"YES\n";
            cout<<a[0]<<'\n';
            goto read;
        }       
        b[0]=0;
        c[0]=1;
        b[1]=a[0]-b[0];
        c[1]=-c[0];       
        ll mn=0,mx=Max;        
        if(c[1]==1) mn=max(mn,-b[1]);
        else if(c[1]==0){
            if(b[1]<0){
                cout<<"NO\n";
                goto read;
            }
        }
        else mx=min(mx,b[1]);        
        for(ll i=2;i<=n;i++){
            b[i]=a[i-1]-b[i-1]-b[i-2];
            c[i]=-c[i-1]-c[i-2];            
            if(c[i]==1) mn = max(mn, -b[i]);
            else if(c[i]==0){
                if(b[i]<0){
                    cout<<"NO\n";
                    goto read;
                }
            }
            else mx=min(mx,b[i]);
        }        
        if(mn>mx){
            cout<<"NO\n";
            goto read;
        }        
        b[n]=a[n-1]-b[n-2];
        c[n]=-c[n-2];        
        ll bd=b[n]-b[n-1];
        ll cd=c[n-1]-c[n];        
        if(cd<0){
            bd=-bd;
            cd=-cd;
        }        
        ll x;        
        if(cd==0){
            if(bd!=0){
                cout<<"NO\n";
                goto read;
            }
            x=mn;
        }
        else{
            if(bd%cd!=0){
                cout<<"NO\n";
                goto read;
            }  
            x=bd/cd;
        }        
        if(x<mn||x>mx){
            cout<<"NO\n";
            goto read;
        }        
        cout<<"YES\n";
        for(ll i=0;i<n;i++){
            cout<<b[i]+c[i]*x <<' ';
        }
        cout<<'\n';
    }    
    return 0;
}