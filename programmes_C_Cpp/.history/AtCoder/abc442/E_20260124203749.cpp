#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct point { int x, y; };
int dir(const point& p) { return p.y || (p.y == 0 && p.x); }
int cmp(const point& a, const point& b) {
    int ua = dir(a), ub = dir(b);
    if (ua != ub) return ua > ub;
    return a.x * b.y - b.x * a.y;
}
int sameLine(const point& a, const point& b) { return a.x * b.y == a.y * b.x; }
void solve() {
    int n, q; cin >> n >> q;
    vector<point> a(n);
    for (auto& [x, y] : a) cin >> x >> y;
    vector b = a;
    sort(a.begin(), a.end(), cmp);
    vector<point> line;
    vector<int> cnt;
    for (int i{}; i < n; ) {
        int j = i;
        while (j < n && sameLine(a[i], a[j])) j ++;
        line.emplace_back(a[i]);
        cnt.emplace_back(j - i);
        i = j;
    }
    int m = line.size();
    for (int i{}; i < m; ++ i) cnt.emplace_back(cnt[i]);
    vector<int> pre(m << 1 | 1, 0);
    for (int i{}; i < 2 * m; ++ i) pre[i + 1] = pre[i] + cnt[i];
    auto get = [&](const point& p) {
        int l{}, r = m;
        while (l < r) {
            int mid = l + r >> 1;
            if (cmp(line[mid], p)) l = mid + 1;
            else r = mid;
        }
        return l;
    };
    while (q --) {
        int A, B; cin >> A >> B; A --, B --;
        point pa = b[A], pb = b[B];
        int la = get(pa), lb = get(pb);
        if (sameLine(pa, pb)) { cout << cnt[la] << "\n"; continue; }
        cout << (lb <= la ? pre[la + 1] - pre[lb] : pre[la + 1 + m] - pre[lb]) << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}