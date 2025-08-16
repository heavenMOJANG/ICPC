#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// Define long long for sums to prevent overflow
using ll = long long;

// Global variables for convenience in DFS
int N;
int K;
vector<ll> A;
vector<vector<int>> adj;
// dp[u][k][0]: u is uncolored
// dp[u][k][1]: u is colored, path is closed
// dp[u][k][2]: u is colored, path is open (upward)
vector<vector<vector<ll>>> dp;

void dfs(int u, int p) {
    // 1. Initialize DP table for the single node u
    // 0 paths, u is uncolored, sum is 0
    dp[u][0][0] = 0;
    if (K >= 1) {
        // 1 path {u}, closed.
        dp[u][1][1] = A[u];
        // 1 path {u}, to be extended upward.
        dp[u][1][2] = A[u];
    }

    // Recursively call DFS on children and merge results
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }

        dfs(v, u);

        // Create a temporary DP table for the merged results.
        auto prev_dp_u = dp[u];
        for (int k = 0; k <= K; ++k) {
            dp[u][k][0] = dp[u][k][1] = dp[u][k][2] = -1;
        }

        for (int ku = 0; ku <= K; ++ku) {
            for (int kv = 0; kv <= K; ++kv) {
                if (ku + kv > K) {
                    continue;
                }

                // --- Calculate max value from v's closed states ---
                ll v_closed_max = -1;
                if (dp[v][kv][0] != -1) v_closed_max = max(v_closed_max, dp[v][kv][0]);
                if (dp[v][kv][1] != -1) v_closed_max = max(v_closed_max, dp[v][kv][1]);

                // --- Calculate max value from v's open state ---
                ll v_open_val = dp[v][kv][2];

                // --- Transitions ---

                // Case 1: u remains uncolored. v must be a closed system.
                if (prev_dp_u[ku][0] != -1 && v_closed_max != -1) {
                    dp[u][ku + kv][0] = max(dp[u][ku + kv][0], prev_dp_u[ku][0] + v_closed_max);
                }

                // Case 2: u becomes/remains part of a CLOSED path.
                // 2a: u was closed, v is closed and disjoint.
                if (prev_dp_u[ku][1] != -1 && v_closed_max != -1) {
                    dp[u][ku + kv][1] = max(dp[u][ku + kv][1], prev_dp_u[ku][1] + v_closed_max);
                }
                // 2b: u was uncolored, path from v comes and ends at u.
                if (prev_dp_u[ku][0] != -1 && v_open_val != -1) {
                    dp[u][ku + kv][1] = max(dp[u][ku + kv][1], prev_dp_u[ku][0] + v_open_val + A[u]);
                }
                // 2c: u was open, path from v meets it, path becomes closed. Path count decreases.
                if (ku + kv >= 1 && prev_dp_u[ku][2] != -1 && v_open_val != -1) {
                     dp[u][ku + kv - 1][1] = max(dp[u][ku + kv - 1][1], prev_dp_u[ku][2] + v_open_val - A[u]);
                }


                // Case 3: u becomes/remains part of an OPEN path.
                // 3a: u was open, v is closed and disjoint.
                if (prev_dp_u[ku][2] != -1 && v_closed_max != -1) {
                    dp[u][ku + kv][2] = max(dp[u][ku + kv][2], prev_dp_u[ku][2] + v_closed_max);
                }
                // 3b: u was uncolored, path from v continues through u.
                if (prev_dp_u[ku][0] != -1 && v_open_val != -1) {
                    dp[u][ku + kv][2] = max(dp[u][ku + kv][2], prev_dp_u[ku][0] + v_open_val + A[u]);
                }
            }
        }
    }
}


int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    A.resize(N + 1);
    adj.resize(N + 1);
    // DP table size (N+1) x (K+1) x 3, initialized to -1
    dp.assign(N + 1, vector<vector<ll>>(K + 2, vector<ll>(3, -1)));

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    
    dfs(1, 0);

    ll max_sum = 0;
    for (int k = 0; k <= K; ++k) {
        // Final answer must be a closed system at the root.
        if (dp[1][k][0] != -1) max_sum = max(max_sum, dp[1][k][0]);
        if (dp[1][k][1] != -1) max_sum = max(max_sum, dp[1][k][1]);
    }

    cout << max_sum << endl;

    return 0;
}