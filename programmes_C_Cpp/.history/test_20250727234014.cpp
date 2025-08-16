#include <iostream>
#include <vector>
#include <numeric>

// 用于解决单个测试用例的函数
void solve() {
    int n;
    std::cin >> n;
    std::vector<long long> b(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> b[i];
    }

    // 'c' 代表结转值或债务
    long long c = 0;
    bool ok = true;

    // 从右到左遍历数组
    for (int i = n - 1; i >= 0; --i) {
        // 更新结转值
        c = b[i] - c;

        // 如果结转值为负，则不可能实现
        if (c < 0) {
            ok = false;
            break;
        }
    }

    // 检查最终条件
    if (ok && c == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }
}

int main() {
    // 加速 C++ I/O 操作
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}