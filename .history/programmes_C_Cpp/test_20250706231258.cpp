#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

// Function to calculate the score for a given array (or vector)
long long calculate_score(const std::vector<int>& arr) {
    long long total_score = 0;
    if (arr.empty()) {
        return 0;
    }
    int current_min = arr[0];
    total_score += current_min;
    for (size_t i = 1; i < arr.size(); ++i) {
        current_min = std::min(current_min, arr[i]);
        total_score += current_min;
    }
    return total_score;
}


void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    // 1. Calculate base score (no operations)
    long long min_total_score = calculate_score(a);

    // 2. Iterate through all possible j's
    for (int j = 1; j < n; ++j) {
        int val_to_add = a[j];
        if (val_to_add == 0) continue;

        // Candidate 1: i = j-1
        // Create the modified prefix a'_1, ..., a'_{j-1}
        std::vector<int> prefix1;
        prefix1.reserve(j);
        for(int k = 0; k < j - 1; ++k) {
            prefix1.push_back(a[k]);
        }
        prefix1.push_back(a[j - 1] + val_to_add);
        min_total_score = std::min(min_total_score, calculate_score(prefix1));

        // Candidate 2: i = 0
        if (j > 0) { // i must be less than j
            std::vector<int> prefix2;
            prefix2.reserve(j);
            prefix2.push_back(a[0] + val_to_add);
            for(int k = 1; k < j; ++k) {
                 prefix2.push_back(a[k]);
            }
            min_total_score = std::min(min_total_score, calculate_score(prefix2));
        }
    }

    std::cout << min_total_score << std::endl;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}