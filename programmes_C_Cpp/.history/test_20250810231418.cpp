#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != b[i]) {
            // If there's a mismatch, we must perform the operation.
            // This is our only and last chance to change a[i].
            a[i] = a[i] ^ a[i+1];
        }
    }

    // After the loop, check if the entire transformed array a matches b.
    // The loop guaranteed a[0]..a[n-2] match b[0]..b[n-2] IF POSSIBLE.
    // The critical check is now the last element.
    if (a[n - 1] == b[n - 1]) {
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