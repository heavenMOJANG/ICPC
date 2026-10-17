#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
using i128 = __int128;
constexpr int INF = 0x7fffffff;
struct Point { int x, y; };
void solve() {
    int N, Q; cin >> N >> Q;
    vector<Point> P(N);
    for (auto & [x, y] : P) cin >> x >> y;
    vector<i128> preA(N + 1, 0), preX{preA}, preY{preA};
    auto cross = [&](Point a, Point b) {
        return (i128)a.x * b.y - (i128)a.y * b.x;
    };
    for (int i : views::iota(0, N)) {
        int j{(i + 1) % N};
        i128 c{cross(P[i], P[j])};
        i128 cx{(i128)(P[i].x + P[j].x) * c};
        i128 cy{(i128)(P[i].y + P[j].y) * c};
        preA[i + 1] = preA[i] + c;
        preX[i + 1] = preX[i] + cx;
        preY[i + 1] = preY[i] + cy;
    }
    auto cal = [&](const vector<i128>& pre, int u, int v) {
        return u < v ? pre[v] - pre[u] : pre[N] - pre[u] + pre[v];
    };
    cout << fixed << setprecision(15);
    while (Q --) {
        int u, v; cin >> u >> v; u --, v --;
        i128 A{cal(preA, u, v)}, X{cal(preX, u, v)}, Y{cal(preY, u, v)};
        i128 c{cross(P[v], P[u])};
        A += c;
        X += (i128)(P[u].x + P[v].x) * c;
        Y += (i128)(P[u].y + P[v].y) * c;
        double f{3.0l * (double)A};
        double aX{(double)X / f}, aY{(double)Y / f};
        cout << aX << " " << aY << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}