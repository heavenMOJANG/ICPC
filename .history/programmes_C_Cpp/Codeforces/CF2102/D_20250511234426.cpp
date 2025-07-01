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
    
}
void solve() {
    int n; cin >> n;
    vector<int> o, e;
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