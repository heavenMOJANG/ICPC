#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
pair<int, int> get(char c) {
    switch (c) {
        case 'U': return {-1ll, 0ll};
        case 'D': return {1ll, 0ll};
        case 'L': return {0ll, -1ll};
        case 'R': return {0ll, 1ll};
    }
    return {0ll, 0ll};
}
bool check(int x, int y) {
    if (y == 0) return false;
    return x % y == 0;
}
void solve() {
    int Rt, Ct, Ra, Ca, N, M, L; cin >> Rt >> Ct >> Ra >> Ca >> N >> M >> L;
    vector<char> S(M), T(L);
    vector<int> A(M), B(L);
    for (int i{}; i < M; ++ i) cin >> S[i] >> A[i];
    for (int i{}; i < L; ++ i) cin >> T[i] >> B[i];
    int i{}, j{}, ca = A[0], cb = B[0];
    int dr = Rt - Ra, dc = Ct - Ca, ans{};
    while (i < M && j < L) {
        int m = min(ca, cb);
        auto s = get(S[i]), t = get(T[j]);
        int ddr = s.first - t.first, ddc = s.second - t.second;
        if (ddr == 0 && ddc == 0) {
            if (dr == 0 && dc == 0) ans += m;
        } else {
            int ok = 1, res = LLONG_MIN;
            if (ddr != 0) {
                if ((-dr) % ddr != 0) ok = 0;
                else res = (-dr) / ddr;
            } else if (dr != 0) ok = 0;
            if (ddc != 0) {
                if ((-dc) % ddc != 0) ok = 0;
                else {
                    int rres = (-dc) / ddc;
                    if (res == LLONG_MIN) res = rres;
                    else if (res != rres) ok = 0;
                }
            } else if (dc != 0) ok = 0;
            if (ok && res != LLONG_MIN && 1 <= res && res <= m) ans ++;
        }
        dr += ddr * m;
        dc += ddc * m;
        ca -= m, cb -= m;
        if (ca == 0) {
            i ++;
            if (i < M) ca = A[i];
        }
        if (cb == 0) {
            j ++;
            if (j < L) cb = B[j];
        }
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}