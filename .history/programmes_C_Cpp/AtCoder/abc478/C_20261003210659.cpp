#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (auto && x : A) cin >> x;
    vector B{A};
    ranges::sort(B);
    int L{-1}, R{-1};
    for (int i : views::iota(0, N))
        if (A[i] != B[i]) {
            if (L == -1) L = i;
            R = i;
        }
    if (L == -1) { cout << "Yes\n"; return; }
    cout << (R - L + 1 <= K ? "Yes\n" : "No\n");
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}