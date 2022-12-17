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

        string s[2];
        cin>>s[0]>>s[1];
        ll x=-1,y=-1,id=-1;

        for(ll i=0;i<n;i++){
            if(id==-1){
                if(s[0][i]=='B'){
                    id=i;
                }
                if(s[1][i]=='B') id=i;
                if(id!=-1){
                    if(s[0][i]=='W'){
                        x=i;
                        y=i-1;
                    }
                    if(s[1][i]=='W'){
                        y=i;
                        x=i-1;
                    }
                }
                continue;
            }
            if(s[0][i]=='W'){
                if(s[1][i]=='W'){
                    id=i-1;
                    break;
                }
                if(s[1][i-1]=='W'){
                    id=i-1;
                    break;
                }
                if((i-y)%2 && y!=-1){
                    //cout<<t<<endl;
                    id=i-1;
                    break;
                }
                if((i-x)%2==0 && x!=-1){
                    id=i-1;
                    break;
                }
                id=i;
                x=i;
                y=i-1;
                continue;
            }
            if(s[1][i]=='W'){
                if(s[0][i]=='W'){
                    id=i-1;
                    break;
                }
                if(s[0][i-1]=='W'){
                    id=i-1;
                    break;
                }
                if((i-x)%2 && x!=-1){
                    id=i-1;
                    break;
                }
                if((i-y)%2==0 && y!=-1){
                    id=i-1;
                    break;
                }
                id=i;
                y=i;
                x=i-1;
                continue;
            }
            id=i;
        }

        //cout<<id<<endl;
        for(ll i=id+1;i<n;i++){
            if(s[0][i]=='B' || s[1][i]=='B'){
                cout<<"NO"<<endl;
                goto read;
            }
        }

        cout<<"YES"<<endl;
    }

    return 0;
}