#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
class DSU {
private:
    int n, siz;
    vector<int> father, siz;
    DSU(int x) : n(x), father(x + 1), siz(x + 1, 1) { iota (father.begin(), father.end(), 0); }
public:
    int findSet(int x) { return 
    }
};
void solve() {
    int n; cin >> n;

    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}