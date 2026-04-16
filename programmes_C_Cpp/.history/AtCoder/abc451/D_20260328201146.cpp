#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    vector<int> D;
    while (N) {
        N --;
        D.emplace_back(N % 4);
        N /= 4;
    }
    reverse(D.begin(), D.end());
    for (int d : D) {
        switch (d) {
            case 0: cout << "1"; break;
            case 1: cout << "2"; break;
            case 2: cout << "4"; break;
            case 3: cout << "8"; break;
        }
    }
    cout << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}