#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string a, b;
        cin >> a >> b;

        vector<int> count0(2 * n + 2, 0);
        vector<int> count1(2 * n + 2, 0);

        // 统计每条对角线的0和1数量
        for (int d = 2; d <= 2 * n; ++d) {
            int start = max(0, d - 1 - (n - 1));
            int end = min(n - 1, d - 2);
            for (int i = start; i <= end; ++i) {
                int j = d - 2 - i;
                int val = (a[i] - '0') ^ (b[j] - '0');
                if (val == 0) count0[d]++;
                else count1[d]++;
            }
        }

        // 计算 count_k，表示(x,y)满足x+y=k的数量
        vector<long long> count_k(2 * n + 2, 0);
        for (int k = 2; k <= 2 * n; ++k) {
            if (k <= n + 1)
                count_k[k] = k - 1;
            else
                count_k[k] = 2LL * n - k + 1;
        }

        // 计算后缀和 S[d] = sum_{k=d}^{2n} count_k[k]
        vector<long long> S(2 * n + 3, 0);
        for (int d = 2; d <= 2 * n; --d) {
            // 这里的循环条件错误，改成下面的正确写法：
        }

        // 修正后缀和计算循环
        for (int d = 2 * n; d >= 2; --d) {
            S[d] = S[d + 1] + count_k[d];
        }

        long long ans = 0;
        for (int d = 2; d <= 2 * n; ++d) {
            int cost = min(count0[d], count1[d]);
            ans += 1LL * cost * S[d];
        }

        cout << ans << "\n";
    }

    return 0;
}
