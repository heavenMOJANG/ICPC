#include <iostream>
#include <vector>
#include <numeric>
#include <set>

// 函数用于检查单个比特位上的转换可能性
bool check_bit(int n, const std::vector<int>& a_bit, const std::vector<int>& b_bit) {
    std::vector<std::set<int>> s(n);

    // 基础情况: i = n-1
    s[n - 1].insert(a_bit[n - 1]);

    // 递推步骤: 从右向左计算所有可能性集合
    for (int i = n - 2; i >= 0; --i) {
        // 不操作
        s[i].insert(a_bit[i]);
        // 操作：用 a[i+1] 的每个可能最终值去异或 a[i]
        for (int val : s[i + 1]) {
            s[i].insert(a_bit[i] ^ val);
        }
    }

    // 验证: 检查 b_bit 的每一位是否都在对应的可能性集合中
    for (int i = 0; i < n; ++i) {
        if (s[i].find(b_bit[i]) == s[i].end()) {
            return false;
        }
    }

    return true;
}

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];

    bool possible = true;
    for (int k = 0; k < 30; ++k) {
        std::vector<int> a_bit(n), b_bit(n);
        for (int i = 0; i < n; ++i) {
            a_bit[i] = (a[i] >> k) & 1;
            b_bit[i] = (b[i] >> k) & 1;
        }

        if (!check_bit(n, a_bit, b_bit)) {
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