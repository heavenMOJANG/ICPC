#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
int tr[N];
int lowbit(int x) { return x & -x; }
void update(int x, int n, int d) { while (x <= n) tr[x] += d, x += lowbit(x); }
int query(int x) {
    int res{};
    while (x) res += tr[x], x -= lowbit(x);
    return res;
}
int calc(vector<int> a) {
    int res{};
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();
    For(i,1,n) {
        //确定num[i]在去重后升序排列的数组中的位置，这里注意要加1，因为树状数组从1开始存
        num[i] = lower_bound(a.begin(),a.end(), num[i] ) - a.begin() + 1;
        //先查询比它大的数的数目，query(m)是总数，query(num[i])是小于等于num[i]的数的数目，相减可得
        ans += query(m)-query(num[i]);
        //再加入树状数组
        update(num[i]);
    }
}
void solve() {
    int n; cin >> n;
    vector<int> o, e;
    o.emplace_back(0); e.emplace_back(0);
    for (int i{}, x; i < n; ++ i) {
        cin >> x;
        if (i & 1) e.emplace_back(x);
        else o.emplace_back(x);
    }

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}