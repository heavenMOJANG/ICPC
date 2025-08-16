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
// dp[u][k][0]: sum for k paths in u's subtree, u is self-contained
// dp[u][k][1]: sum for k paths in u's subtree, u is upward-connecting
vector<vector<vector<ll>>> dp;

void dfs(int u, int p) {
    // 1. Initialize DP table for the current node u.
    // States are -1 if invalid/unreachable.
    
    // Base case: 0 paths, u is self-contained (uncolored), sum is 0.
    dp[u][0][0] = 0;
    // Base case: 1 path...
    if (1 <= K) {
        // Path is just {u}, self-contained. Sum is A[u].
        dp[u][1][0] = A[u];
        // Path starts at u and goes up. Sum in this subtree is A[u].
        dp[u][1][1] = A[u];
    }

    // Recursively call DFS on children and merge results
    for (int v : adj[u]) {
        if (v == p) {
            continue;
        }

        dfs(v, u);

        // Create a temporary DP table for the merged results. This is crucial
        // to avoid using partially updated values of dp[u] in the same merge step.
        vector<vector<ll>> new_dp(K + 1, vector<ll>(2, -1));

        for (int ku = 0; ku <= K; ++ku) {
            // Skip if the state in u's part is unreachable
            if (dp[u][ku][0] == -1 && dp[u][ku][1] == -1) continue;

            for (int kv = 0; kv <= K; ++kv) {
                // Skip if the state in v's part is unreachable
                if (dp[v][kv][0] == -1 && dp[v][kv][1] == -1) continue;

                // --- Case 1: New state for u is self-contained ---
                
                // 1a: u(self-contained) + v(self-contained). Path sets are disjoint.
                if (ku + kv <= K && dp[u][ku][0] != -1 && dp[v][kv][0] != -1) {
                    new_dp[ku + kv][0] = max(new_dp[ku + kv][0], dp[u][ku][0] + dp[v][kv][0]);
                }
                
                // 1b: u(upward) + v(upward). Paths from two subtrees merge at u.
                if (ku + kv - 1 <= K && ku + kv >=1 && dp[u][ku][1] != -1 && dp[v][kv][1] != -1) {
                    new_dp[ku + kv - 1][0] = max(new_dp[ku + kv - 1][0], dp[u][ku][1] + dp[v][kv][1]);
                }

                // --- Case 2: New state for u is upward-connecting ---

                // 2a: u(upward) + v(self-contained). u's upward path continues, v's paths are separate.
                if (ku + kv <= K && dp[u][ku][1] != -1 && dp[v][kv][0] != -1) {
                    new_dp[ku + kv][1] = max(new_dp[ku + kv][1], dp[u][ku][1] + dp[v][kv][0]);
                }

                // 2b: u(self-contained) + v(upward). Path from v extends through u.
                // THIS IS THE CORRECTED TRANSITION
                if (ku + kv <= K && dp[u][ku][0] != -1 && dp[v][kv][1] != -1) {
                    new_dp[ku + kv][1] = max(new_dp[ku + kv][1], dp[u][ku][0] + dp[v][kv][1] + A[u]);
                }
            }
        }
        // Update u's DP table with the new, merged results
        dp[u] = new_dp;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    // Resize vectors and use 1-based indexing
    A.resize(N + 1);
    adj.resize(N + 1);
    dp.assign(N + 1, vector<vector<ll>>(K + 1, vector<ll>(2, -1)));

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int U, V;
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    
    // Start DFS from root (node 1), with a virtual parent 0
    dfs(1, 0);

    // The final answer is the maximum value among all self-contained states at the root,
    // for any number of paths from 0 to K.
    ll max_sum = 0;
    for (int k = 0; k <= K; ++k) {
        if (dp[1][k][0] != -1) {
            max_sum = max(max_sum, dp[1][k][0]);
        }
    }

    cout << max_sum << endl;

    return 0;
}