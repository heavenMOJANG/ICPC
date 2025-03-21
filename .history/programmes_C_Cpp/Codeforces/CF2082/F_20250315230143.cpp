#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 3e5 + 10;
int n, a[N], L[N], R[N], cnt[N];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> a[i];
        cnt[a[i]] ++;
        if (cnt[a[i]] == 1) L[i] = L[i - 1] + 1;
        else L[i] = L[i - 1];
    }
    for (int i = 1; i <= n; ++ i) {
        cnt[a[i]] --;
        if ()
    }
    return 0;
}