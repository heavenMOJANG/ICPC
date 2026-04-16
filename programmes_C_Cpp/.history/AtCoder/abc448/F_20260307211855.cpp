#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Point { int x, y, id, key; };
int getKey(int x, int y) {
    int res{};
    for (int i{}; i < 25; ++ i) {
        res |= ((y >> i) & 1) << (2 * i);
        res |= ((x >> i) & 1) << (2 * i + 1);
    }
    return res;
}
void solve() {
    int n; cin >> n;
    vector<Point> a(n);
    for (int i{}; i < n; ++ i) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i + 1;
        a[i].key = getKey(a[i].x, a[i].y);
    }
    sort(a.begin(), a.end(), [](const Point& A, const Point& B) {
        if (A.key != B.key) return A.key < B.key;
        return A.id < B.id;
    });
    int pos = -1;
    for (int i{}; i < n; ++ i) if (a[i].id == 1) { pos = i; break; }
    for (int i{}; i < n; ++ i) cout << a[(pos + i) % n].id << " \n"[i == n - 1];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}