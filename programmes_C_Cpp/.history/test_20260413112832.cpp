#include <iostream>

using namespace std;

// 定义在全局域，自动初始化为 0，防止栈溢出
long long dp[7][19][64][64];

// 跨平台兼容的位运算统计（Brian Kernighan 算法）
int count_ones(int n) {
    int count = 0;
    while (n) {
        n &= (n - 1);
        count++;
    }
    return count;
}

int main() {
    // 初始状态：第 0 行，剩余 18 个 1，列全 0 掩码和列全 1 掩码均为 63 (0x3F)
    dp[0][18][63][63] = 1;

    for (int r = 0; r < 6; r++) {
        for (int ones = 0; ones <= 18; ones++) {
            for (int mz = 0; mz < 64; mz++) {
                for (int mo = 0; mo < 64; mo++) {
                    if (dp[r][ones][mz][mo] == 0) continue;

                    // 枚举当前行填入的模式 (1 到 62，排除了全 0 和全 1)
                    for (int mask = 1; mask < 63; mask++) {
                        int current_ones = count_ones(mask);
                        
                        if (ones >= current_ones) {
                            int next_mz = mz & (~mask);
                            int next_mo = mo & mask;
                            
                            dp[r + 1][ones - current_ones][next_mz][next_mo] += dp[r][ones][mz][mo];
                        }
                    }
                }
            }
        }
    }

    // 提取最终合法状态的总数
    long long ans = dp[6][0][0][0];

    // 使用单次输出流，避免终端缓冲区截断或分行刷新失败
    cout << "====== 状态压缩 DP 验证 ======\n"
         << "数学理论值 : 7199875940\n"
         << "程序搜索值 : " << ans << "\n"
         << (ans == 7199875940LL ? "=> 验证成功！" : "=> 验证失败！") << "\n";

    return 0;
}