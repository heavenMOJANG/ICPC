#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 4e18;
void solve() {
    struct INTERVAL { int L, R, A, B; };
    int n; cin >> n;
    vector<int> P(n), A(n), B(n);
    for (int i{}; i < n; ++ i) cin >> P[i] >> A[i] >> B[i];
    vector<INTERVAL> seg, nxt;
    seg.emplace_back(0ll, INF, 1ll, 0ll);
    for (int i{}; i < n; ++ i) {
        nxt.clear();
        for (auto s : seg) {
            auto [L, R, a, b] = s;
            if (a == 1) {
                int d0 = P[i] - b;
                if (L <= d0) nxt.emplace_back(L, min(R, d0), 1ll, b + A[i]);
                int dl = max(L, d0 + 1);
                if (dl <= R) {
                    int d1 = B[i] - b - 1;
                    if (dl <= d1) nxt.emplace_back(dl, min(R, d1), 0ll, 0ll);
                    int d2 = max(dl, d1 + 1);
                    if (d2 <= R) nxt.emplace_back(d2, R, 1ll, b - B[i]); 
                }
            } else {
                if (b <= P[i]) nxt.emplace_back(L, R, 0ll, b + A[i]);
                else {
                    int d = b - B[i];
                    if (d > 0) nxt.emplace_back(L, R, 0ll, d);
                    else nxt.emplace_back(L, R, 0ll, 0ll);
                }
            }
        }
        seg.clear();
        for (auto s : nxt)
            if (seg.empty() || seg.back().A != s.A || seg.back().B != s.B || seg.back().R + 1 != s.L)
                seg.emplace_back(s);
            else seg.back().R = s.R;
    }
    int q; cin >> q;
    vector<pair<int, int>> qs(q);
    for(int i{}; i < q; ++ i)
        cin >> qs[i].first, qs[i].second = i;
    sort(qs.begin(), qs.end());
    vector<long long> ans(Q);

// 双指针：j 走过 segs， i 走过 qs
int i = 0, j = 0;
int S = segs.size();
while(i < Q && j < S){
    long long x = qs[i].first;
    auto &seg = segs[j];
    // 如果 x 在当前段里，直接算出答案
    if (seg.L <= x && x <= seg.R) {
        ans[qs[i].second] = seg.a ? x + seg.b : seg.b;
        i++;
    }
    else if (x < seg.L) {
        // 当前查询太小，还没到本段
        // 那它一定落在前一个段（不会真的出现，因为第 0 段左端是 0），
        // 或者本来就 < 0，题里 X ≥ 0，不会发生
        ans[qs[i].second] = 0;
        i++;
    }
    else {
        // x > seg.R，往下一段走
        j++;
    }
}
// （剩余 i< Q 的情况，要么所有段都穷尽了，此时直接用最后一段的 a,b）
while(i < Q){
    auto &seg = segs.back();
    long long x = qs[i].first;
    ans[qs[i].second] = seg.a ? x + seg.b : seg.b;
    i++;
}

// 输出
for(long long v: ans){
    cout << v << "\n";
}
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}