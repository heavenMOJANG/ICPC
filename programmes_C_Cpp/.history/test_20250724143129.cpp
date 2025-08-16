#include <iostream>
#include <vector>
#include <cmath>

void solve() {
    int n;
    std::cin >> n;
    if (n == 1) {
        std::cout << "1\n1\n";
        return;
    }
    int k = 0;
    while ((1 << (k + 1)) <= n) {
        k++;
    }
    int sz = 2 * k + 2;
    std::vector<std::vector<int>> a(sz, std::vector<int>(sz, 0));

    for (int i = 0; i < k + 1; ++i) {
        a[i][i] = 1;
        a[i + k + 1][i + k + 1] = 1;
        a[i][i + k + 1] = 1;
    }

    for (int i = 0; i < k; ++i) {
        a[i + 1][i] = 1;
        a[i + k + 1][i + k + 2] = 1;
    }

    int rem = n - (1 << k);
    int cur = 1;
    for (int i = 0; i < k; ++i) {
        if ((rem >> i) & 1) {
            a[i + 1][k] = 1;
        }
    }
    if (rem) {
        a[0][k] = 1;
    }

    std::cout << sz << "\n";
    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            std::cout << a[i][j] << (j == sz - 1 ? "" : " ");
        }
        std::cout << "\n";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    solve();
    return 0;
}