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
        ll n,x;
        cin>>n>>x;

        ll m=n,temp=(1LL<<62)-1;
        for(ll i=61;i>=0;i--){
            if((m&(1LL<<i))==(x&(1LL<<i))){
                temp-=(1LL<<i);
                continue;
            }
            if(!(m&(1LL<<i)) && (x&(1LL<<i))){
                cout<<-1<<endl;
                goto read;
            }
            m|=temp;
            m++;
            break;
            //cout<<temp<<endl;
        }
        if((m&n)!=x) m=-1;
        cout<<m<<endl;
    }

    return 0;
}