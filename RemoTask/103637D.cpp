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

const ll N=1001;

bitset<N> read_val(){
    bitset<N> a;
    string s;
    cin>>s;
    ll k=0;
    for(ll i=0;i<s.size();){
        if(s[i]=='0'){
            i++;
            continue;
        }
        ll c=0;
        for(ll j=i;j<s.size();j++){
            ll x=s[j]-'0';
            c=10*c+x;
            s[j]=(char)(c/2+'0');
            c%=2;
        }
        a[k++]=c;
    }
    return a;
}

bitset<N> mask[N],subset[N],a[N];
void build(ll idx){
    bitset<N> temp_subset,temp;
    temp=a[idx];
    temp_subset[idx]=1;
    for(ll i=0;i<N;i++){
        if(temp[i]==0) continue;
        if(mask[i]==0){
            mask[i]=temp;
            subset[i]=temp_subset;
            break;
        }
        temp^=mask[i];
        temp_subset^=subset[i];
    }
}

void update(ll idx){
    ll temp=-1;
    for(ll i=N-1;i>=0;i--){
        if(temp==-1){
            if(subset[i][idx]) temp=i;
            continue;
        }
        if(subset[i][idx]){
            mask[i]^=mask[temp];
            subset[i]^=subset[temp];
        }
    }
    mask[temp].reset();
    subset[temp].reset();
}

bitset<N> query(bitset<N> val){
    bitset<N> temp;
    for(ll i=0;i<N;i++){
        if(val[i]==0) continue;
        val^=mask[i];
        temp^=subset[i];
    }
    temp[0]=1;
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0);
    int n,m;
    cin>>n>>m;

    for(ll i=0;i<=n;i++){
        a[i]=read_val();
    }

    for(ll i=1;i<=n;i++){
        build(i);
    }

    bitset<N> ans=query(a[0]);

    ll p=ans.count();
    cout<<p<<"\n";
    for(ll i=0;i<=n;i++){
        if(ans[i]){
            cout<<i<<" ";
            p^=i;
        }
    }cout<<"\n";

    while(m--){
        ll t;
        cin>>t;
        if((t^p)==0) a[0]=read_val();
        else{
            update(t^p);
            a[t^p]=read_val();
            build(t^p);
        }

        ans=query(a[0]);

        p=ans.count();
        cout<<p<<"\n";
        for(ll i=0;i<=n;i++){
            if(ans[i]){
                cout<<i<<" ";
                p^=i;
            }
        }cout<<"\n";
    }

    return 0;
}
