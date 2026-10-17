#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, M; cin >> N >> M;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    vector<int> B(N - 1);
    for (auto && x : B) cin >> x;
    int sum{}, tmp{}, cnt{};
    vector<pii> vp;
    for (int i{}; i < N; ++ i) {
        int res{((tmp - A[i]) % M + M) % M};
        sum += res;
        if (i & 1) {
            cnt --;
            if (res != M - 1) vp.emplace_back(res + 1, M);
        } else {
            cnt ++;
            if (res) vp.emplace_back(M - res, -M);
        }
        if (i < N - 1) tmp = ((B[i] - tmp) % M + M) % M;
    }
    ranges::sort(vp);
    int ans{sum}, cur{sum}, X{};
    for (int i{}, siz{(int)vp.size()}; i < siz;) {
        int res{vp[i].first};
        ans = min(ans, cur + cnt * (res - X - 1));
        cur += cnt * (res - X);
        X = res;
        while (i < siz && vp[i].first == res) cur += vp[i ++].second;
        ans = min(ans, cur);
    }
    cout << min(ans, cur + cnt * (M - 1 - X)) << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}