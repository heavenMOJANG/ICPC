#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> fac(6, 1);
    for (int i{1}; i < 6; ++ i) fac[i] = fac[i - 1] * 11;
    int siz{fac[5] * 11};
    vector<int> A(siz);
    auto getId = [&](string S, bool f) -> int {
        int res{};
        for (int i{}; i < 6; ++ i) {
            int X{S[i] - '0'};
            if (f) X ++;
            res += X * fac[i];
        }
        return res;
    };
    while (N --) {
        string S; cin >> S;
        int V; cin >> V;
        A[getId(S, 1)] += V;
    }
    for (int d{}; d < 6; ++ d)
        for (int i{}; i < siz; ++ i) if ((i / fac[d]) % 11) A[i] += A[i - fac[d]];
    int Q; cin >> Q;
    while (Q --) {
        string x, y; cin >> x >> y;
        bool ok{1};
        for (int i{}; i < 6; ++ i) if (x[i] > y[i]) ok = 0;
        if (!ok) { cout << "0\n"; continue; }
        int ans{};
        for (int mask{}; mask < 64; ++ mask) {
            int id{}, cnt{};
            for (int i{}; i < 6; ++ i) {
                int res;
                if (mask >> i & 1) res = x[i] - '0', cnt ++;
                else res = y[i] - '0' + 1;
                id += res * fac[i];
            }
            if (cnt & 1) ans -= A[id];
            else ans += A[id];
        }
        cout << ans << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}