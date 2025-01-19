#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
    int ans{};
    {
        int cnt1{}, cnt2{};
        if (x1 > y1) cnt1 ++; else if (x1 < y1) cnt2 ++;
        if (x2 > y2) cnt1 ++; else if (x2 < y2) cnt2 ++;
        ans += (cnt1 > cnt2);
    }
    {
        int cnt1{}, cnt2{};
        if (x1 > y2) cnt1 ++; else if (x1 < y2) cnt2 ++;
        if (x2 > y1) cnt1 ++; else if (x2 < y1) cnt2 ++;
        ans += (cnt1 > cnt2);
    }
    {
        int cnt1{}, cnt2{};
        if (x2 > y1) cnt1 ++; else if (x2 < y1) cnt2 ++;
        if (x1 > y2) cnt1 ++; else if (x1 < y2) cnt2 ++;
        ans += (cnt1 > cnt2);
    }
    {
        int cnt1{}, cnt2{};
        if (x2 > y2) cnt1 ++; else if (x2 < y2) cnt2 ++;
        if (x1 > y1) cnt1 ++; else if (x1 < y1) cnt2 ++;
        ans += (cnt1 > cnt2);
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}