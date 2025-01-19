#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++ i) cin >> a[i];
    int idx = 0, ans = 0;
    vector<int>siz(n + 1), son(n + 1), dfn(n + 1), ctr(n + 1), rnk(n + 1);
    map<int, int>cnt(n + 1);
    function<void(int)> add = [&](int u) {
        cnt[a[u]] ++;
    };
    function<void(int)> del = [&](int u) {
        cnt[a[u]] --;
    };
    function<int> getAns = [&]() {return 0;};
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}