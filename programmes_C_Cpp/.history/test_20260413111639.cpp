#pragma GCC optimize("O3,unroll-loops")
#include <iostream>
#include <chrono>

using namespace std;

// 状态空间：dp[7][19][64][64]
// 7   : 记录行数 (0 到 6)
// 19  : 记录剩余1的数量 (0 到 18)
// 64  : 列全0掩码 (0 到 63)
// 64  : 列全1掩码 (0 到 63)
long long dp[7][19][64][64];

int main() {
    auto start_time = chrono::high_resolution_clock::now();

    // 初始化：第0行，还剩18个1需要分配。
    // 初始状态下，没有任何行打破列全0或全1的属性，所以掩码均为 63 (即二进制 111111)
    dp[0][18][63][63] = 1;

    for (int r = 0; r < 6; r++) {
        for (int ones = 0; ones <= 18; ones++) {
            for (int mz = 0; mz < 64; mz++) {
                for (int mo = 0; mo < 64; mo++) {
                    
                    if (dp[r][ones][mz][mo] == 0) continue;

                    // 枚举当前行填入的模式 mask
                    // 题目要求：不能有任何一行全0或全1，所以范围是从 1 到 62 (0x3E)
                    for (int mask = 1; mask < 63; mask++) {
                        int current_ones = __builtin_popcount(mask); // 当前行消耗的1的数量
                        
                        if (ones >= current_ones) {
                            // 位运算更新列状态
                            int next_mz = mz & (~mask);
                            int next_mo = mo & mask;
                            
                            dp[r + 1][ones - current_ones][next_mz][next_mo] += dp[r][ones][mz][mo];
                        }
                    }
                }
            }
        }
    }

    // 最终我们需要取 第6行填满、1全部用完(剩0个)、且没有任何一列全0 (mz=0)、没有任何一列全1 (mo=0) 的总方案数
    long long ans = dp[6][0][0][0];

    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> elapsed = end_time - start_time;

    cout << "数学理论值 (Math Result) : 7199875940" << endl;
    cout << "程序搜索值 (Search Result): " << ans << endl;
    if (ans == 7199875940LL) {
        cout << "=> 验证成功！(Verified Successfully)" << endl;
    } else {
        cout << "=> 验证失败！(Verification Failed)" << endl;
    }
    cout << "程序耗时 (Time elapsed)  : " << elapsed.count() << " ms" << endl;

    return 0;
}