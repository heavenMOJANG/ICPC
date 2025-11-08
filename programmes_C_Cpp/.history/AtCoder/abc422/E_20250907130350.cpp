#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y; };
mt19937_64 rnd(time(NULL));
void solve() {
    int n; cin >> n;
    vector<Point> p(n);
    for (int i{}; i < n; ++ i) cin >> p[i].x >> p[i].y;
    uniform_int_distribution<int> dis(0, n - 1);
    for (int i{}; i < 20; ++ i) {
        int id1 = dis(rnd), id2 = dis(rnd);
        while (id1 == id2) id2 = dis(rnd);
        const auto& p1 = p[id1];
        const auto& p2 = p[id2];
        int A = p2.y - p1.y, B = p1.x - p2.x, C = -B * p1.y - A * p1.x;
        int cnt{};
        for (int j{}; j < n; ++ j) if (A * p[j].x + B * p[j].y + C == 0) cnt ++;
        if (cnt * 2 > n) {
            cout << "Yes\n" << A << " " <<  B << " " << C << "\n";
            return;
        }
    }
    cout << "No\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}