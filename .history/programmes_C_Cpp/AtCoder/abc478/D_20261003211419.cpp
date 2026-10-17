#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Query { int X, L, R; };
void solve() {
    int N, Q; cin >> N >> Q;
    vector<Query> queries(Q);
    for (int i : views::iota(0, Q)) cin >> queries[i].L >> queries[i].R >> queries[i].X;
    sort(queries.begin(), queries.end(), [](const Query& a, const Query& b) {
        if (a.X != b.X) return a.X < b.X;
        if (a.L != b.L) return a.L < b.L;
        return a.R < b.R;
    });
    vector<int> diff(N + 2, 0);
    int p{};
    while (p < Q) {
        int X{queries[p].X}, cL{queries[p].L}, cR{queries[p].R};
        p ++;
        while (p < Q && queries[p].X == X) {
            int L{queries[p].L}, R{queries[p].R};
            if (L <= cR + 1) cR = max(cR, R);
            else {
                diff[cL] ++;
                diff[cR + 1] --;
                cL = L, cR = R;
            }
            p ++;
        }
        diff[cL] ++;
        diff[cR + 1] --;
    }
    for (int i : views::iota(1, N + 1)) diff[i] += diff[i - 1];
    for (int i : views::iota(1, N + 1)) cout << diff[i] << " \n"[i == N];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}