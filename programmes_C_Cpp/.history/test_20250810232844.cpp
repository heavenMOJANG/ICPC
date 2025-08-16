#include <iostream>
#include <vector>
#include <numeric>
#include <set>

// 函数用于检查单个比特位上的转换可能性
bool check_bit(int n, const std::vector<int>& a_bit, const std::vector<int>& b_bit) {
    // S_next 代表 S_{i+1}
    std::set<int> s_next;
    s_next.insert(a_bit[n - 1]);

    if (s_next.find(b_bit[n - 1]) == s_next.end()) {
        return false;
    }

    for (int i = n - 2; i >= 0; --i) {
        // 计算 S_i
        std::set<int> s_current;
        s_current.insert(a_bit[i]);
        for (int val : s_next) {
            s_current.insert(a_bit[i] ^ val);
        }

        // 检查 b_bit[i] 是否在 S_i 中
        if (s_current.find(b_bit[i]) == s_current.end()) {
            return false;
        }
        
        // 为下一次迭代更新 S_next
        s_next = s_current;
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