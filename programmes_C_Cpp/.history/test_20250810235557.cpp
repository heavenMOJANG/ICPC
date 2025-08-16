#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    // 最后一个位置不能被修改，如果不同直接NO
    if (a[n - 1] != b[n - 1]) {
        cout << "NO\n";
        return;
    }

    vector<int> vis(n - 1, 0); // 标记操作是否做过
    queue<int> q;

    auto can = [&](int i) {
        return !vis[i] && ( (a[i] ^ a[i+1]) == b[i] );
    };

    // 初始化队列
    for (int i = 0; i < n - 1; i++) {
        if (can(i)) q.push(i);
    }

    while (!q.empty()) {
        int i = q.front(); q.pop();
        if (vis[i]) continue;
        vis[i] = 1;

        // 执行操作 ai = ai ^ ai+1
        a[i] ^= a[i+1];

        // 检查邻居
        if (i - 1 >= 0 && can(i - 1)) q.push(i - 1);
        if (i + 1 < n - 1 && can(i + 1)) q.push(i + 1);
    }

    // 检查结果
    if (a == b) cout << "YES\n";
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    cin >> T;
    while (T--) solve();
    return 0;
}
