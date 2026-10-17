#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> pw(6, 1);
    for (int i{1}; i < 6; ++ i) pw[i] = pw[i - 1] * 11;
    int siz{pw[5] * 11};
    vector<int> A(siz);
    auto getId = [&](string S, bool f) -> int {
        int res{};
        for (int i{}; i < 6; ++ i) {
            int X{S[i] - '0'};
            if (f) X ++;
            res += X * pw[i];
        }
        return res;
    };
    while (N --) {
        string S; cin >> S;
        int V; cin >> V;
        A[getId(S, 1)] += V;
    }
    for (int d{}; d < 6; ++ d)
        for (int i{}; i < siz; ++ i) 
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}