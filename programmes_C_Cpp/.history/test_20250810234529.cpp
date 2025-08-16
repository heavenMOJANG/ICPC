#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<unsigned int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;

    if (a[n - 1] != b[n - 1]) { // 最后一个必须相等
        cout << "NO\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] != b[i]) {
            unsigned int need = a[i] ^ b[i];
            if (a[i + 1] != need) { // 无法匹配
                cout << "NO\n";
                return;
            }
            a[i] ^= a[i + 1]; // 执行操作
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) solve();
}
