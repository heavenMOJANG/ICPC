#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
class FenwickTree {
public:
    int n;
    vector<int> tree;
    FenwickTree(int _n) : n(_n), tree(_n, 0) {}
    void modify() {}
private:
    int lowbot(int x) { return x & (-x); }
};
int n, m, a[N], ans;
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    return 0;
}