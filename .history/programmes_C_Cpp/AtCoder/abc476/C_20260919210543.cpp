#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i : views::iota(0, N)) {
        pq.push(A[i]);
        if (pq.size() > 3) pq.pop();
        if (i >= 2) cout << pq.top() << "\n";
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}