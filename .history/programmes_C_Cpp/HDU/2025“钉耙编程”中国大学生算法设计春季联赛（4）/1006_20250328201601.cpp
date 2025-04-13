#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
//#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct FenwickTree {
	int n;
	vector<int> t;
	FenwickTree(int _n) : n(_n), t(_n + 1) {}
	void set(int i, int x) {
		for (++ i; i <= n; i += i & -i) t[i] += x;
	}
	int sum(int i) {
		int res{};
		for (++ i; i; i -= i & -i) res += t[i];
		return res;
	}
	int sum(int l, int r) {
		return sum(r) - sum(l - 1);
	}
};
void solve() {
    int n, q; cin >> n >> q;
	FenwickTree ft(n);
	vector<int> a(n + 1);
    for (int i = 1, x; i <= n; ++ i) cin >> x, ft.set(i, x);
    int ans{}, cnt = 1;
    while (q --) {
        int op, x, y; cin >> op >> x >> y;
        if (op == 1) {
			seg.set(x, y);
		}
        else {
            int l = x == 1 ? 0 : seg.prod(1, x) / 100, r = seg.prod(1, y + 1) / 100;
            ans ^= (r - l) * cnt;
            cnt ++;
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}