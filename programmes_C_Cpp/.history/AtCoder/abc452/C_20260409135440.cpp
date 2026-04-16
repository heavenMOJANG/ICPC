#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i{}; i < N; ++ i) cin >> A[i] >> B[i];
    int M; cin >> M;
    vector<string> S(M);
    for (int i{}; i < M; ++ i) cin >> S[i];
    vector v(N, vector<int>(26, 0));
    for (const string& s : S) {
        for (int i{}; i < N; ++ i)
            if (A[i] == s.size()) v[i][s[B[i] - 1] - 'a'] = 1;
    }
    for (const string& s : S) {
        if (s.size() != N) { cout << "No\n"; continue; }
        int ok = 1;
        for (int i{}; i < N; ++ i)
            if (!v[i][s[i] - 'a']) { ok = 0; break; }
        cout << (ok ? "Yes\n" : "No\n");
    }
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}
