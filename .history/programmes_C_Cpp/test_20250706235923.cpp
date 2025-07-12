#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (n < k) { // Cannot perform any operation
        std::cout << (n == 0 ? "YES\n" : "NO\n");
        return;
    }
    
    // An empty array is a palindrome
    if (n == 0) {
        std::cout << "YES\n";
        return;
    }

    int matched_pairs = 0;
    while (matched_pairs < n / 2 && a[matched_pairs] == a[n - 1 - matched_pairs]) {
        matched_pairs++;
    }

    int core_size = n - 2 * matched_pairs;

    if (core_size == 0) {
        // Already a palindrome
        std::cout << "YES\n";
    } else {
        // We need to remove the 'core_size' elements.
        // To do this, we need to perform 'core_size' operations.
        // The array size must be >= k for all operations.
        // The smallest the array will get is 2 * matched_pairs.
        // If we want to remove the entire core, its size must be at most the number of "extra" elements we have past k.
        // Number of elements we can remove is n - (k-1).
        // So, we need core_size <= n - (k-1).
        // n - 2*p <= n - k + 1  => k-1 <= 2*p
        // But a simpler argument is that k helpers are needed to remove something without touching the core.
        // If we have p helpers on each side, we need k <= p to be sure.
        if (k <= matched_pairs) {
             std::cout << "YES\n";
        } else {
             std::cout << "NO\n";
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}