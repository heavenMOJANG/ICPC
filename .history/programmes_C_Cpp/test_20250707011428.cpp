#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>
#include <set>

// Function to check if a vector is a palindrome
bool is_palindrome(const std::vector<int>& v) {
    int n = v.size();
    if (n <= 1) return true;
    for (int i = 0; i < n / 2; ++i) {
        if (v[i] != v[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    long long k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    if (k == 1) {
        std::cout << "YES\n";
        return;
    }

    // --- Iterative Removal Process ---
    std::vector<bool> active(n, true);
    int active_count = n;

    while (true) {
        if (active_count < k) {
            break;
        }

        std::map<int, int> counts;
        for (int i = 0; i < n; ++i) {
            if (active[i]) {
                counts[a[i]]++;
            }
        }

        std::map<int, long long> C_le;
        long long cumulative_count = 0;
        for (auto const& [val, num] : counts) {
            cumulative_count += num;
            C_le[val] = cumulative_count;
        }

        int val_to_remove = -1;
        for (auto it = counts.rbegin(); it != counts.rend(); ++it) {
            int v = it->first;
            long long count_le = C_le[v];
            long long count_v = it->second;
            long long count_lt = count_le - count_v;

            if (count_lt < k && count_le >= k) {
                val_to_remove = v;
                break;
            }
        }
        
        if (val_to_remove == -1) {
            break; // No more removable elements
        }

        for (int i = 0; i < n; ++i) {
            if (active[i] && a[i] == val_to_remove) {
                active[i] = false;
                active_count--;
            }
        }
    }

    // --- Final Palindrome Check ---
    int p = 0;
    while (p < n / 2 && a[p] == a[n - 1 - p]) {
        p++;
    }

    if (2 * p >= n) {
        std::cout << "YES\n";
        return;
    }

    std::vector<int> stuck_subsequence;
    for (int i = p; i < n - p; ++i) {
        if (active[i]) {
            stuck_subsequence.push_back(a[i]);
        }
    }

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