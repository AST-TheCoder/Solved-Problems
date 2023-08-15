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

ll x_0, y_0, x_1, y_1;

void exgcd(ll x, ll x1, ll y, ll y1) {
    while (x != 0){
        ll k = x1 / x;
        y1 = y1 - y * k;
        x1 = x1 - x * k;
        swap(x1, x);
        swap(y1, y);
    }
    x_0 = x1, y_0 = y1;
    y_1 = __gcd(y_1, abs(y));
}

void update(ll x, ll y){
    if (x < 0){
        x = -x;
        y = -y;
    }
    if (x == 0){
        y_1 = __gcd(y_1, abs(y));
        return;
    }
    if (x_0 == 0){
        x_0 = x, y_0 = y;
        return;
    }
    else{
        exgcd(x, x_0, y, y_0);
    }
}

bool check(ll x, ll y){
    if (x == 0 && y == 0) return true;
    if (x_0 == 0){
        if (y_0 == 0) return false;
        if (y % y_0 == 0) return true;
        return false;
    }
    if (x % x_0 != 0) return false;
    y = y - (x / x_0) * y_0;
    if (y == 0) return true;
    if (y_1 == 0 || y % y_1 != 0)   return false;
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    int cas = 0;
    while (T--){
        int n;
        scanf("%d", &n);
        int x, y, w;
        x_0 = y_0 = x_1 = y_1 = 0;
        ll ans = 0;
        for (int i = 1; i <= n; i++){
            int opt;
            scanf("%d", &opt);
            if (opt == 1){
                scanf("%d%d", &x, &y);
                update(x, y);
                if (y_1 > 0) y_0 = (y_0 % y_1 + y_1) % y_1;
            }
            else{
                scanf("%d%d%d", &x, &y, &w);
                if (check(x, y)) ans = ans + w;
            }
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}