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
    // freopen("sum_41_chapter_1_input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    vector<ll> p;
    for(ll i=2;i<=41;i++){
        ll c=0;
        for(ll j=2;j<i;j++){
            if(i%j==0) c++;
        }
        if(!c){
            p.pb(i);
        }
    }

    ll t,ii=0;
    cin>>t;

    while(t--){
        ll n;
        cin>>n;
        ll c[42],s=0;
        min_heap<ll> v;
        memset(c,0,sizeof(c));
        for(ll i=0;i<p.size();i++){
            while(n%p[i]==0){
                n/=p[i];
                c[p[i]]++;
                s+=p[i];
                v.push(p[i]);
            }
        }
        cout<<"Case #"<<++ii<<":";
        if(s>41 || n!=1){
            cout<<" -1"<<endl;
            continue;
        }

        while(s<41 && v.size()>2){
            ll x=v.top();
            v.pop();
            ll y=v.top();
            v.pop();
            if(s-(x+y)+(x*y)>41){
                v.push(x);
                v.push(y);
                break;
            }
            s+=(x*y)-(x+y);
            v.push(x*y);
        }

        while(s<41){
            v.push(1);
            s++;
        }

        cout<<" "<<v.size();
        while(!v.empty()){
            cout<<" "<<v.top();
            v.pop();
        }
        cout<<endl;
    }

    return 0;
}