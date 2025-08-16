#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

// Function to check if it's possible to finish with 'x' initial coins
bool check(long long x, int H, int W, const vector<vector<int>>& A, const vector<int>& P) {
    vector<vector<long long>> dp(H, vector<long long>(W, -1));

    // Base case: Starting at (0, 0)
    if (x + A[0][0] >= P[0]) {
        dp[0][0] = x + A[0][0] - P[0];
    } else {
        return false; // Fail at the very beginning
    }

    // Fill the DP table
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (i == 0 && j == 0) continue;

            int day = i + j;
            long long cost = P[day];
            long long coins_on_cell = A[i][j];

            // Path from above
            long long from_up = -1;
            if (i > 0 && dp[i - 1][j] != -1) {
                if (dp[i - 1][j] + coins_on_cell >= cost) {
                    from_up = dp[i - 1][j] + coins_on_cell - cost;
                }
            }

            // Path from the left
            long long from_left = -1;
            if (j > 0 && dp[i][j - 1] != -1) {
                if (dp[i][j - 1] + coins_on_cell >= cost) {
                    from_left = dp[i][j - 1] + coins_on_cell - cost;
                }
            }
            
            // Take the path that leaves the most coins
            dp[i][j] = max(from_up, from_left);
        }
    }

    // Check if the destination is reachable
    return dp[H - 1][W - 1] != -1;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, W;
    cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> P(H + W - 1);
    for (int i = 0; i < H + W - 1; ++i) {
        cin >> P[i];
    }

    // Binary search for the minimum initial coins
    long long low = 0;
    long long high = 4e14; // A sufficiently large upper bound
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, H, W, A, P)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}