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

    // 从左到右（i 从 0 到 n-2）贪心
    for (int i = 0; i < n - 1; ++i) {
        // 如果 a[i] 已经等于 b[i]，我们假设不执行操作。
        // 这是因为执行操作会改变 a[i]，使其不再等于 b[i]。
        // 如果 a[i] 不等于 b[i]，我们必须执行操作，这是改变 a[i] 的唯一机会。
        if (a[i] != b[i]) {
            a[i] = a[i] ^ a[i+1];
        }
    }

    // 在所有操作决策做出后，检查整个数组是否匹配。
    // 循环保证了如果可能，a[0]..a[n-2] 中的每个元素都被设置为 b 的对应值
    // （通过一次操作）。
    // 现在需要检查最终的 a 是否等于 b。
    bool possible = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            possible = false;
            break;
        }
    }

    if (possible) {
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