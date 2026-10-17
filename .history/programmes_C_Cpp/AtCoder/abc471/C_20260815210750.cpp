#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int N; cin >> N;
    set<int> s;
    for (int i : views::iota(0, N)) {
        int A; cin >> A;
        s.insert(A);
    }
    int cur{}, ans{};
    while (!s.empty()) {
        auto r{s.lower_bound(cur)};
        int hasR{r != s.end()}, hasL{r != s.begin()};
        auto select{s.end()};
        if (!hasL) select = r;
        else if (!hasR) select = prev(r);
        else {
            auto l{prev(r)};
            int dl{cur - *l}, dr{*r - cur};
            if (dl <= dr) select = l;
            else select = r;
        }
        int nxt{*select};
        ans += abs(cur - nxt);
        cur = nxt;
        s.erase(select);
    }
    cout << ans << "\n";
    return;
}
signed main() {
    cin.tie(nullptr) -> sync_with_stdio(false);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}