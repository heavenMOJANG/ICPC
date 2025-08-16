#include <iostream>
#include <vector>
#include <numeric>

// 为二维向量定义一个类型别名，方便使用
using matrix = std::vector<std::vector<int>>;

// 递归函数，用于构造行列式为 n 的矩阵
matrix build(int n) {
    // 基础情况: n=1
    if (n == 1) {
        return {{1}};
    }
    
    // 递归步骤：首先构造 k = (n+1)/2 的矩阵
    int k_val = (n + 1) / 2;
    matrix sub_matrix = build(k_val);
    int m = sub_matrix.size();

    // 创建一个比子矩阵大一号的新矩阵
    matrix new_matrix(m + 1, std::vector<int>(m + 1, 0));

    // 1. 将子矩阵 A_k 复制到新矩阵的左上角
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            new_matrix[i][j] = sub_matrix[i][j];
        }
    }
    
    // 2. 按照规则填充新矩阵的最后一行和最后一列，以构造 A_{2k}
    //    这个构造可以保证 det(new_matrix) = 2 * det(sub_matrix) = 2k
    for (int i = 0; i < m; ++i) {
        new_matrix[i][m] = sub_matrix[i][m - 1]; // 复制最后一列
        new_matrix[m][i] = sub_matrix[m - 1][i]; // 复制最后一行
    }
    new_matrix[m][m] = 1;

    // 3. 如果 n 是奇数，我们需要的是 2k-1，而不是 2k
    //    通过将右下角的 1 改为 0，行列式的值会减 1
    if (n % 2 != 0) {
        new_matrix[m][m] = 0;
    }

    return new_matrix;
}

int main() {
    // 优化 C++ 的输入/输出速度
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n_in;
    std::cin >> n_in;

    matrix result_matrix = build(n_in);
    int size = result_matrix.size();

    // 输出结果
    std::cout << size << std::endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << result_matrix[i][j] << (j == size - 1 ? "" : " ");
        }
        std::cout << std::endl;
    }

    return 0;
}
