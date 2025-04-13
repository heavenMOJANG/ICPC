#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node { int ch[2], sum{}; } t[N << 5];
int idx;
void insert(int& p, int d, const int x) {
    t[++ idx] = t[p];
    p = idx;
    t[p].sum ++;
    if (t < 0) return;
    int val = (x >> d) ^ 1;
    insert(t[p].ch[val], d - 1, x);
}
void solve() {
    int n, q; cin >> n >> q;

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}