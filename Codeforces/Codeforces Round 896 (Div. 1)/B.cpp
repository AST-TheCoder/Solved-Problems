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

    ll p[40];
    p[0]=1;
    for(ll i=1;i<40;i++) p[i]=p[i-1]*2;

    ll t;
    cin>>t;

    read:
    while(t--){
        ll n;
        cin>>n;

        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }

        ll s=0;
        for(ll i=0;i<n;i++){
            s+=a[i];
        }
        if(s%n){
            cout<<"No"<<endl;
            continue;
        }
        s/=n;

        ll x[40],y[40];
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(ll i=0;i<n;i++){
            if(a[i]==s) continue;
            ll d=s-a[i],f=0;
            for(ll j=0;j<40;j++){
                for(ll k=0;k<40;k++){
                    ll temp=p[j]-p[k];
                    if(temp==d){
                        x[j]++;
                        y[k]++;
                        f=1;
                        break;
                    }
                }
            }
        }

        for(ll i=0;i<n;i++){
            if(a[i]==s) continue;
            ll d=s-a[i],f=0;
            for(ll j=0;j<40;j++){
                for(ll k=0;k<40;k++){
                    ll temp=p[j]-p[k];
                    if(temp==d){
                        if(y[j]){
                            a[i]+=p[j];
                            y[j]--;
                        }
                        if(x[k]){
                            a[i]-=p[k];
                            x[k]--;
                        }
                        f=1;
                        break;
                    }
                }
            }
        }

        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));

        for(ll i=0;i<n;i++){
            if(a[i]==s) continue;
            ll d=s-a[i],f=0;
            cout<<i<<" "<<d<<" "<<a[i]<<endl;
            for(ll j=0;j<40;j++){
                if(d==p[j]){
                    x[j]++;
                    f=1;
                }
                if(d==-p[j]){
                    y[j]++;
                    f=1;
                }
            }
            if(!f){
                cout<<"No"<<endl;
                goto read;
            }
        }

        for(ll i=0;i<40;i++){
            if(x[i]!=y[i]){
                cout<<"No"<<endl;
                goto read;
            }
        }

        cout<<"Yes"<<endl;
    }

    return 0;
}