#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (k == 1) {
            // k=1，能删任意元素，答案总是YES
            cout << "YES\n";
            continue;
        }

        bool ok = true;
        for (int i = 0; i < k - 1; i++) {
            if (a[i] != a[n - 1 - i]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }

    return 0;
}
