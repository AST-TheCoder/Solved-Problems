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
        ll n,pos;
        cin>>n;

        string a,b;
        cin>>a>>b;

        if(a==b){
            cout<<0<<endl;
            goto read;
        }
        if(count(all(a),'1')==0 || count(all(b),'1')==0){
            cout<<-1<<endl;
            goto read;
        }
        if(n==1 && a!=b){
            cout<<-1<<endl;
            goto read;
        }

        

        vector<ll> ans;
        for(ll i=0;i<n;i++){
            pos=-1;
            if(a[i]==b[i]) continue;
            for(ll j=0;j<n;j++){
                if(i==j) continue;
                if(a[j]=='1'){
                    pos=j;
                    break;
                }
            }

            ll c=0;
            if(pos==-1){
                for(ll j=0;j<n;j++){
                    if(i==j) continue;
                    if(b[j]=='1'){
                        pos=j;
                        break;
                    }
                }
                c=0;
            }
            
            ans.pb(pos-i);
            if(pos>i){
                ll d=pos-i;
                string temp=a;
                for(ll j=0;j<d;j++) temp+='0';
                for(ll j=a.size()-1,k=temp.size()-1;j>=0;j--,k--){
                    if(a[j]==temp[k]) a[j]='0';
                    else a[j]='1';
                }
            }
            else{
                ll d=i-pos;
                string temp=a;
                reverse(all(temp));
                for(ll j=0;j<d;j++) temp+='0';
                reverse(all(temp));
                for(ll j=0,k=0;j<a.size();j++,k++){
                    if(a[j]==temp[k]) a[j]='0';
                    else a[j]='1';
                }
            }
            if(c==-1) i--;
        }

        cout<<ans.size()<<endl;
        for(ll i=0;i<ans.size();i++) cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}