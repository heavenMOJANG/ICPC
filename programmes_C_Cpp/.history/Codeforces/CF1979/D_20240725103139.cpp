#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    s = " " + s;
    vector<int> suf1(n + 2, 1), suf2(n + 2, 1);
    vector<int> cnt1(n + 2), cnt2(n + 2);
    for (int i = n - k; i >= 1; -- i) {
        if (s[i] == s[i + k]) suf1[i] = 0;
        suf1[i] &= suf1[i + 1];
    }
    cnt1[n] = 1;
    for (int i = n - 1; i >= 1; -- i)
        if (s[i] == s[i + 1]) cnt1[i] = cnt1[i + 1] + 1;
        else cnt1[i] = 1;
    reverse(s.begin() + 1, s.end());
    for (int i = n - k; i >= 1; -- i) {
        if (s[i] == s[i + k]) suf2[i] = 0;
        suf2[i] &= suf2[i + 1];
    }
    cnt2[n] = 1;
    for (int i = n - 1; i >= 1; -- i)
        if (s[i] == s[i + 1]) cnt2[i] = cnt2[i + 1] + 1;
        else cnt2[i] = 1;
    reverse(s.begin() + 1, s.end());\
    auto check = [&](int p) {
        if (p == n) return suf2[1] & cnt2[1] == k;
        if (!suf1[p] || !suf2[n - p + 1]) return 0ll;
        int t = n / k;
        if (t % 2 == 0 && s[1] == s[p + 1]) return 0ll;
        if (t & 1 && s[1] != s[p + 1]) return 0ll;
        if (n - p >= k) {
            if (cnt1[p + 1] != k) return 0ll;
        } else {
            if (cnt1[p + 1] != n - p) return 0ll;
        }
        if (p >= k) {
            if (cnt2[n - k + 1] != k) return 0ll;
        } else {
            if (cnt2[n - p + 1] != p) return 0ll;
        }
        return 1ll;
    };
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}