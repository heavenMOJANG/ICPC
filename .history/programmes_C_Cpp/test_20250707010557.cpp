#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

// Function to check if a vector is a palindrome
bool is_palindrome(const std::vector<int>& v) {
    int n = v.size();
    if (n == 0) {
        return true;
    }
    for (int i = 0; i < n / 2; ++i) {
        if (v[i] != v[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    std::map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        counts[a[i]]++;
    }

    if (k == 1) {
        std::cout << "YES\n";
        return;
    }

    // Pre-calculate count_less for each value
    std::map<int, int> count_less;
    int cumulative_count = 0;
    for (auto const& [val, num] : counts) {
        count_less[val] = cumulative_count;
        cumulative_count += num;
    }

    // Strip outer palindromic part
    int p = 0;
    while (p < n / 2 && a[p] == a[n - 1 - p]) {
        p++;
    }

    // If core is empty or single element, it's a palindrome
    if (p * 2 >= n - 1) {
        std::cout << "YES\n";
        return;
    }

    // Construct the subsequence of "stuck" elements from the core
    std::vector<int> stuck_subsequence;
    for (int i = p; i < n - p; ++i) {
        // An element is stuck if we can't gather k-1 smaller elements
        // from the entire original array to form a deletion window.
        if (count_less[a[i]] < k - 1) {
            stuck_subsequence.push_back(a[i]);
        }
    }

    // The stuck elements cannot be removed. Their subsequence must form a palindrome.
    if (is_palindrome(stuck_subsequence)) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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