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

    // for(ll a=-10;a<=10;a++){
    //     for(ll b=a;b<=10;b++){
    //         for(ll c=b;c<=10;c++){
    //             for(ll d=c;d<=10;d++){
    //                 for(ll e=d;e<=10;e++){
    //                     for(ll f=e;f<=10;f++){
    //                         for(ll g=f;g<=10;g++){
    //                             for(ll h=g;h<=10;h++){
    //                                 vector<ll> v;
    //                                 v.pb(a);
    //                                 v.pb(b);
    //                                 v.pb(c);
    //                                 v.pb(d);
    //                                 v.pb(e);
    //                                 v.pb(f);
    //                                 v.pb(g);
    //                                 v.pb(h);
    //                                 ll chk=1;
    //                                 sort(all(v));
    //                                 do{
    //                                     if(v[0]*v[1]*v[2]*v[3]!=v[4]+v[5]+v[6]+v[7]){
    //                                         chk=0;
    //                                         break;
    //                                     }
    //                                 }while(next_permutation(all(v)));
    //                                 if(chk) cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<" "<<g<<" "<<h<<endl;
    //                             }
    //                         }
                            
    //                     }
    //                 }
    //             }
    //         }
    //     }
    // }

    ll t;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;

        ll a[2*n];
        for(ll i=0;i<2*n;i++) cin>>a[i];

        if(n==1){
            cout<<abs(a[0]-a[1])<<endl;
            continue;
        }
        ll ans=Max;
        if(n==2){
            ans=0;
            ans+=abs(a[0]-2);
            ans+=abs(a[1]-2);
            ans+=abs(a[2]-2);
            ans+=abs(a[3]-2);
        }
        //cout<<ans<<" "<<"C\n";
        ll temp=0;
        for(ll i=0;i<2*n;i++) temp+=abs(a[i]);
        ans=min(ans,temp);
        sort(a,a+2*n);

        if(n%2==0){
            temp=0;
            for(ll i=0;i<2*n;i++){
                if(i+1==2*n) temp+=abs(n-a[i]);
                else temp+=abs(a[i]+1);
            }
            ans=min(ans,temp);
        }
        cout<<ans<<endl;
    }

    return 0;
}