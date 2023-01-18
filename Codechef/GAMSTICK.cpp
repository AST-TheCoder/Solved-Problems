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
        ll n,x1,y1,x2,y2,ok=0;
        cin>>n>>x1>>y1>>x2>>y2;

        string ans[2];
        ans[0]="Miron";
        ans[1]="Slava";

        if(y1>y2){
            y1=n-y1+1;
            y2=n-y2+1;
            ok=1;
        }

        if(y1==y2){
            cout<<"Draw"<<"\n";
            continue;
        }

        if(x1==x2){
            ll p=(y1+y2)/2;
            ll q=p+1;
            q=n-q+1;
            if(p>q) cout<<ans[ok]<<"\n";
            else if(p==q) cout<<"Draw"<<"\n";
            else cout<<ans[!ok]<<"\n";
            continue;
        }

        ll p=(y1+y2)/2;
        ll q=p+1;

        ll m1=p-y1;
        ll m2=y2-q;

        if(m1>m2){
            ll pos=(n+1)/2;
            if(q<=pos) cout<<ans[!ok]<<"\n";
            else if((n%2 && p<=pos) || (n%2==0 && p<=pos+1)) cout<<"Draw"<<"\n";
            else cout<<ans[ok]<<"\n";
            continue;
        }

        ll pos=n/2+1;
        if(p>=pos) cout<<ans[ok]<<"\n";
        else if((n%2 && q>=pos) || (n%2==0 && q>=pos-1)) cout<<"Draw"<<"\n";
        else cout<<ans[!ok]<<"\n";
    }

    return 0;
}