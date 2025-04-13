#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int M = 2e5 + 10;
struct Edge { int to, nxt, val; } e[M];
struct Node {
	int id, d;
	bool operator < (const Node &a) const { return d > a.d; }
};
int n, m, k, ds;

void solve() {
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}