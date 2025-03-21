#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 3e5 + 10;
int n, a[N], L[N], R[N], cnt[N];
struct segmentTree {
    vector<int> val, tag;
    segmentTree(int _n): val(4 * n + 10, 0), tag(4 * n + 10, 0) {}
    void pushUp(int p) { val[p] = max(val[p << 1], val[p << 1 | 1]); }
    void update0(int L, int R, int )
};
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        cnt[a[i]] ++;
        if (cnt[a[i]] == 1) L[i] = L[i - 1] + 1;
        else L[i] = L[i - 1];
    }
    R[1] = L[n];
    for (int i = 2; i <= n; ++ i) {
        cnt[a[i - 1]] --;
        if (!cnt[a[i - 1]]) R[i] = R[i - 1] - 1;
        else R[i] = R[i - 1];
    }
    return 0;
}