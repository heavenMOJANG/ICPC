#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Fenwick {
	int n;
	vector<int> tr;
	Fenwick(int _n) : n(_n), tr(_n + 1) { fill(tr.begin(), tr.end(), 0); }
	int lb(int x) { return x & -x; }
	void set(int x, int v) { for (int i = x; i <= n; i += lb(i)) tr[i] += v; }
	int sum(int x) { int res = 0; for (int i = x; i; i -= lb(i)) res += tr[i]; return res; }
};
void solve() {
    int n, q; cin >> n >> q;
	vector<int> a(n + 1);
	Fenwick ft(n);
	for (int i = 1; i <= n; ++ i) cin >> a[i], ft.set(i, a[i]);
    int ans{}, cnt = 1;
    while (q --) {
        int op, x, y; cin >> op >> x >> y;
        if (op == 1) {
			ft.set(x, y - a[x]);
			a[x] = y;
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