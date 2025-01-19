#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
int fastPow(int a, int x) {
    int res = 1;
    while (x) {
        if (x & 1) res = res * a;
        a = a * a;
        x >>= 1;
    }
    return res;
}
int check (int x) {
    int f = sqrt(x);
    return f * f == x;
}
void solve() {
    int n; cin >> n;
    string L, R; cin >> L >> R;
    int LL{}, LR{}, RL{}, RR{};
    int k = n / 2;
    for (int i = 0; i < k; ++ i) LL = LL * 10 + (L[i] - 48);
    for (int i = k; i < n; ++ i) LR = LR * 10 + (L[i] - 48);
    for (int i = 0; i < k; ++ i) RL = RL * 10 + (R[i] - 48);
    for (int i = k; i < n; ++ i) RR = RR * 10 + (R[i] - 48);
    int cntLR = (int)(floor(sqrt(fastPow(10, k) - 1)) - ceil(sqrt(LR)) + 1);
    int cntRR = (int)(floor(sqrt(RR)) - ceil(sqrt(0)) + 1);
    int cntL = (int)(floor(sqrt(RL)) - ceil(sqrt(LL)) + 1);
    int cntR = (int)(floor(sqrt(fastPow(10, k) - 1)) - ceil(sqrt(fastPow(10, k))) + 1);
    if (LL) cntL --;
    if (RL) cntL --;
    cntL = max(0ll, cntL);
    int ans = cntLR + cntL * cntR + cntRR;
    cout << ans << "\n";
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}