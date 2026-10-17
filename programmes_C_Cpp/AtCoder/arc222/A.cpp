#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
struct Node {
    int L, R;
    bool operator < (const Node& o) const {
        if (L != o.L) return L < o.L;
        return R > o.R;
    }
};
void solve() {
    int N, M; cin >> N >> M;
    vector<Node> B(M);
    for (int i{}; i < M; ++ i) cin >> B[i].L >> B[i].R;
    sort(B.begin(), B.end());
    vector<Node> C;
    int maxr{-1};
    for (const auto& x : B)
        if (x.R > maxr) C.emplace_back(x), maxr = x.R;
    vector<int> init(N + 1);
    iota(init.begin(), init.end(), 1);
    priority_queue<int, vector<int>, greater<int>> pq(init.begin(), init.end());
    vector<int> freq(N + 10, 0), A(N + 10, 0);
    int l{1}, r{}, j{}, m{(int)C.size()};
    for (int i{1}; i <= N; ++ i) {
        while (j < m && C[j].R < i) j ++;
        int ll{i};
        if (j < m && C[j].L <= i) ll = C[j].L;
        while (r < i - 1) freq[A[++ r]] ++;
        while (l < ll) {
            freq[A[l]] --;
            if (freq[A[l]] == 0) pq.push(A[l]);
            l ++;
        }
        while (freq[pq.top()] > 0) pq.pop();
        A[i] = pq.top();
    }
    for (int i{1}; i <= N; ++ i) cout << A[i] << " \n"[i == N];
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}