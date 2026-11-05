#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y; };
int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
bool upper(Point p) { return p.y > 0 || (p.y == 0 && p.x > 0); }
//読むと偏角ソートになる
void solve() {
    int N; cin >> N;
    vector<Point> P(N);
    for (auto && [x, y] : P) cin >> x >> y;
    sort(P.begin(), P.end(), [](Point a, Point b) {
        return upper(a) != upper(b) ? upper(a) > upper(b) : cross(a, b) > 0;
    });
    for (int i : views::iota(0, N)) P.emplace_back(P[i]);
    int ans{}, r{};
    for (int l : views::iota(0, N)) {
        r = max(r, l + 1);
        while (r < l + N && cross(P[l], P[r]) > 0) r ++;
        ans = max(ans, r - l);
    }
    cout << ans << "\n";
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}