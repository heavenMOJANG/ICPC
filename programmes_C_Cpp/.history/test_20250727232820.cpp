#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        // 1) 计算总长度和：n(n+1)(n+2)/6
        ll N = n;
        ll total = N * (N + 1) * (N + 2) / 6;

        // 2) 减去每个升点 i*(n-i)
        ll sub = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (p[i] < p[i+1]) {
                sub += ll(i+1) * ll(n - (i+1));
                // 注意 C++ 下标 i 从 0 开始，对应公式中的 i = (i+1)
            }
        }

        cout << (total - sub) << "\n";
    }

    return 0;
}
