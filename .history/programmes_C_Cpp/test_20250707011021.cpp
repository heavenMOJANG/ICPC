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
    std::map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        counts[a[i]]++;
    }

    if (k == 1) {
        std::cout << "YES\n";
        return;
    }

    // --- Iterative Peeling to find all stuck values ---
    std::vector<int> distinct_vals;
    for (auto const& [val, num] : counts) {
        distinct_vals.push_back(val);
    }

    std::map<int, long long> C_le;
    long long cumulative_count = 0;
    for (auto const& [val, num] : counts) {
        cumulative_count += num;
        C_le[val] = cumulative_count;
    }

    std::set<int> stuck_values;
    for (int val : distinct_vals) {
        if (C_le[val] < k) {
            stuck_values.insert(val);
        }
    }
    
    bool changed = true;
    while(changed){
        changed = false;
        std::map<int, long long> stuck_le_counts;
        long long current_stuck_le = 0;
        for (auto const& [val, num] : counts) {
            if(stuck_values.count(val)){
                current_stuck_le += num;
            }
            stuck_le_counts[val] = current_stuck_le;
        }

        for (int val : distinct_vals) {
            if (stuck_values.count(val)) continue;
            
            if (stuck_le_counts[val] + counts[val] < k) {
                stuck_values.insert(val);
                changed = true;
            }
        }
    }

    // --- Check if the stuck subsequence is a palindrome ---
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
        if (stuck_values.count(a[i])) {
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