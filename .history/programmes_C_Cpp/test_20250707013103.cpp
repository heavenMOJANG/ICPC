#include <iostream>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

const int MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> restrictions(n + 1);
    for (int k = 0; k < m; ++k) {
        int i, x;
        cin >> i >> x;
        restrictions[i].push_back(x);
    }

    vector<vector<long long>> C(n + 2, vector<long long>(n + 2, 0));
    for (int i = 1; i <= n; ++i) {
        for (int l = 1; l <= n - i + 1; ++l) {
            set<int> forbidden_r;
            for (int p = i; p < i + l; ++p) {
                for (int x : restrictions[p]) {
                    if (x <= l) {
                        // a[p] = (r + (p-i) - 1) % l + 1
                        // forbidden if (r + p - i - 1) % l + 1 == x
                        // r_0 + (p-i) = x-1 (mod l) where r_0 = r-1
                        // r_0 = (x-1 - (p-i)) mod l
                        long long r0_forbidden = (long long)x - 1 - (p - i);
                        r0_forbidden = (r0_forbidden % l + l) % l;
                        forbidden_r.insert(r0_forbidden);
                    }
                }
            }
            C[i][l] = l - forbidden_r.size();
        }
    }

    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
    vector<vector<long long>> A(n + 2, vector<long long>(n + 2, 0));

    for (int i = 1; i <= n + 1; ++i) {
        dp[i][0] = 1;
    }

    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            // Calculate A[i][l]
            long long decomposable_count = 0;
            for (int k = 1; k < l; ++k) {
                long long term = (A[i][k] * dp[i + k][l - k]) % MOD;
                decomposable_count = (decomposable_count + term) % MOD;
            }
            A[i][l] = (C[i][l] - decomposable_count + MOD) % MOD;

            // Calculate dp[i][l]
            long long dp_val = 0;
            for (int j = 1; j <= l; ++j) {
                long long term = (A[i][j] * dp[i + j][l - j]) % MOD;
                dp_val = (dp_val + term) % MOD;
            }
            dp[i][l] = dp_val;
        }
    }

    cout << dp[1][n] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}