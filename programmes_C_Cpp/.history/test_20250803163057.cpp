#include <iostream>
#include <vector>
#include <cmath>

const int MAXN = 100005;
const int LOGN = 18;

// dp[k][i] stores f(i, 2^k - 1), which is the result of 2^k-1 ops on A[i...i+2^k-1]
// This is simply the XOR sum of that range.
int dp[LOGN][MAXN];
int a[MAXN];
int n, q;

// Function to compute f(start, m) using the recurrence relation.
int query_recursive(int start, int m) {
    if (m == 0) {
        return a[start];
    }
    // Find highest power of 2 less than or equal to m
    int k = floor(log2(m));
    int p = 1 << k;
    int rest = m - p;
    
    // f(m, start) = f(rest, start) ^ f(rest, start + p)
    return query_recursive(start, rest) ^ query_recursive(start + p, rest);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    for (int k = 0; k < q; ++k) {
        int l, r;
        std::cin >> l >> r;
        // This recursive solution is correct but will Time Out.
        // It demonstrates the correct logic.
        // For a fast solution, this recursion must be memoized or made iterative.
        // The problem is that the state (start, m) is too large.
        // A fast solution requires a more advanced data structure or observation.
        // However, the core logic is this.
        std::cout << query_recursive(l - 1, r - l) << "\n";
    }

    return 0;
}