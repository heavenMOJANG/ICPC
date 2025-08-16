#include <iostream>
#include <vector>
#include <cmath>

// 一个辅助函数，用于计算表示一个正整数所需的位数。
// 对于 N > 0，它等价于 floor(log2(N)) + 1。
int get_bit_length(int n) {
    if (n == 0) return 0;
    int count = 0;
    long long temp = n;
    while (temp > 0) {
        temp >>= 1;
        count++;
    }
    return count;
}

int main() {
    // 优化 C++ 的输入/输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_in;
    std::cin >> n_in;

    // 处理 N=1 的基本情况
    if (n_in == 1) {
        std::cout << 1 << std::endl;
        std::cout << 1 << std::endl;
        return 0;
    }

    // 确定矩阵大小
    int n_out = get_bit_length(n_in);

    // 初始化一个 n x n 的矩阵，所有元素为 0
    std::vector<std::vector<int>> matrix(n_out, std::vector<int>(n_out, 0));

    // 构造矩阵的基础结构
    // 这部分创建了一个结构，使得在行列式展开期间，
    // 子式（cofactor）能够产生2的幂。
    for (int i = 0; i < n_out - 1; ++i) {
        matrix[i][i] = 1;     // 主对角线 (除了最后一个元素)
        matrix[i+1][i] = 1;   // 次对角线
    }

    // 将 N 的二进制位放入矩阵的最后一列
    // 最后一列的第 i 行对应 N 的第 i 位
    for (int i = 0; i < n_out; ++i) {
        if ((n_in >> i) & 1) {
            matrix[i][n_out - 1] = 1;
        }
    }

    // 输出结果
    std::cout << n_out << std::endl;
    for (int i = 0; i < n_out; ++i) {
        for (int j = 0; j < n_out; ++j) {
            std::cout << matrix[i][j] << (j == n_out - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}