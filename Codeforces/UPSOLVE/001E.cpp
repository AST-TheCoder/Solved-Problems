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

class segment_tree{
    public:
    vector<ll> node_max,node_min,prop;

    segment_tree(){
        for(ll i=0;i<=1000000;i++){
            node_max.pb(0);
            node_min.pb(0);
            prop.pb(0);
        }
    }

    void update(ll n,ll l,ll r,ll i,ll j,ll v){
        if(l!=r){
            prop[2*n]+=prop[n];
            prop[2*n+1]+=prop[n];
            node_max[2*n]+=prop[n];
            node_max[2*n+1]+=prop[n];
            node_min[2*n]+=prop[n];
            node_min[2*n+1]+=prop[n];
        }
        prop[n]=0;
        if(j<l || i>r) return;
        if(i<=l && r<=j){
            node_max[n]+=v;
            node_min[n]+=v;
            prop[n]=v;
            return;
        }
        update(2*n,l,(l+r)/2,i,j,v);
        update(2*n+1,(l+r)/2+1,r,i,j,v);
        node_max[n]=max(node_max[2*n],node_max[2*n+1]);
        node_min[n]=min(node_min[2*n],node_min[2*n+1]);
    }

    ll query_neg(ll n,ll l,ll r,ll x){
        if(l!=r){
            prop[2*n]+=prop[n];
            prop[2*n+1]+=prop[n];
            node_max[2*n]+=prop[n];
            node_max[2*n+1]+=prop[n];
            node_min[2*n]+=prop[n];
            node_min[2*n+1]+=prop[n];
        }
        prop[n]=0;
        if(node_min[n]>=0) return -1;
        if(l==r) return l;
        if(!x){
            if(node_min[2*n]<0) return query_neg(2*n,l,(l+r)/2,x);
            else return query_neg(2*n+1,(l+r)/2+1,r,x);
        }
        else{
            if(node_min[2*n+1]<0) return query_neg(2*n+1,(l+r)/2+1,r,x);
            else return query_neg(2*n,l,(l+r)/2,x);
        }
    }

    ll query_pos(ll n,ll l,ll r,ll x){
        if(l!=r){
            prop[2*n]+=prop[n];
            prop[2*n+1]+=prop[n];
            node_max[2*n]+=prop[n];
            node_max[2*n+1]+=prop[n];
            node_min[2*n]+=prop[n];
            node_min[2*n+1]+=prop[n];
        }
        prop[n]=0;
        if(node_max[n]<2) return -1;
        if(l==r) return l;
        if(!x){
            if(node_max[2*n]>=2) return query_pos(2*n,l,(l+r)/2,x);
            else return query_pos(2*n+1,(l+r)/2+1,r,x);
        }
        else{
            if(node_max[2*n+1]>=2) return query_pos(2*n+1,(l+r)/2+1,r,x);
            else return query_pos(2*n,l,(l+r)/2,x);
        }
    }
};

int main()
{

    ll n,qq;
    cin>>n>>qq;

    string s;
    cin>>s;

    segment_tree a=segment_tree();
    segment_tree b=segment_tree();

    ll x=0,y=0;
    for(ll i=0;i<n;i++){
        if(s[i]=='(') x++;
        else y++;
    }

    for(ll i=0;i<n;i++){
        if(s[i]=='(') a.update(1,0,n-1,i,n-1,1);
        else a.update(1,0,n-1,i,n-1,-1);
    }

    for(ll i=n-1;i>=0;i--){
        if(s[i]=='(') b.update(1,0,n-1,0,i,-1);
        else b.update(1,0,n-1,0,i,1);
    }

    while(qq--){
        ll id;
        cin>>id;
        id--;
        if(s[id]=='('){
            a.update(1,0,n-1,id,n-1,-2);
            b.update(1,0,n-1,0,id,2);
            s[id]=')';
            x--,y++;
        }
        else{
            a.update(1,0,n-1,id,n-1,2);
            b.update(1,0,n-1,0,id,-2);
            s[id]='(';
            x++,y--;
        }

        ll p=a.query_neg(1,0,n-1,0);
        ll q=a.query_pos(1,0,n-1,0);

        ll u=b.query_neg(1,0,n-1,1);
        ll v=b.query_pos(1,0,n-1,1);
        
        if(abs(x-y)%2){
            cout<<"NO"<<endl;
            continue;
        }
        if(p!=-1 && (q==-1 || p<q)){
            cout<<"NO"<<endl;
            continue;
        }
        if(u!=-1 && (v==-1 || u>v)){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}