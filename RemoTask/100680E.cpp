#include <bits/stdc++.h>
#define all(a) (a).begin(),(a).end()
#define ld long double
#define ll long long
#define sqr(a) (a)*1ll*(a)
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define inf (int)1e9
#define pi pair<int,int>
#define y1 fdfs
using namespace std;
const ld eps = 1e-9;
int n,x[4],y[4];
ld dist(ld x1,ld y1,ld x2,ld y2)
{
    return sqrt(sqr(x1-x2)+sqr(y1-y2));
}
ld f(ld X,ld Y)
{
    ld z = 0;
    for(int i=0;i<4;++i)
        z+=dist(X,Y,x[i],y[i]);
    return z;
}
void solve()
{
    ld ans = 1e18, X ,Y;
    for(int i=0;i<4;++i)
    for(int j=i+1;j<4;++j)
    {
        int A1 = y[i] - y[j];
        int B1 = x[j] - x[i];
        ll C1 = -A1*x[i]-B1*y[i];
        int i1=-1,j1=-1;
        for(int k=0;k<4;++k)
        {
            if(k==i||k==j) continue;
            if(i1==-1) i1 = k;
                  else j1 = k;
        }
        int A2 = y[i1] - y[j1];
        int B2 = x[j1] - x[i1];
        ll C2 = -A2*x[i1]-B2*y[i1];
        ll D = A1*B2 - A2*B1;
        if(!D) continue;
        ld x5 = (C2*B1 - C1*B2)/(D+0.);
        ld y5 = (A2*C1 - A1*C2)/(D+0.);
        if(f(x5,y5)<ans) ans = f(x5,y5), X = x5, Y = y5;
    }
    for(int i=0;i<4;++i)
        if(f(x[i],y[i])<ans) ans = f(x[i],y[i]), X = x[i], Y = y[i];
    cout.precision(10);
    cout<<fixed<<X<<' '<<fixed<<Y<<"\n";
}
int main()
{
    // freopen("clover.in","r",stdin);
    // freopen("clover.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin>>n;
    while(n--)
    {
        for(int i=0;i<4;++i)
            cin>>x[i]>>y[i];
        solve();
    }
}