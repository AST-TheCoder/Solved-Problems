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

    ll t,ii=0;
    cin>>t;
    cin.ignore();

    while(t--){
        string s;
        getline(cin,s);

        //cout<<s<<endl;
        ll cnt[260];
        memset(cnt,0,sizeof(cnt));

        for(ll i=0;i<s.size();i++){
            cnt[s[i]]++;
        }
        cout<<"Case "<<++ii<<": ";

        if(cnt['S']<2 || cnt['E']<2 || !cnt['L'] || !cnt['I']){
            cout<<"NONE"<<endl;
            continue;
        }
        if(cnt[' ']<2 || !cnt['D'] || !cnt['P'] || cnt['i']<2 || !cnt['g'] || cnt['t']<2 || cnt['a']<2 || cnt['l']<2 || !cnt['f'] || !cnt['o'] || !cnt['r'] || !cnt['m'] || !cnt['s']){
            cout<<"SELISE"<<endl;
            continue;
        }
        cout<<"BOTH"<<endl;
    }

    return 0;
}