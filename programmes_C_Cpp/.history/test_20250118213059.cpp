#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long max_units(int N, long long M, vector<long long>& P) {
    long long total_units = 0;  // 总购买量
    long long total_cost = 0;   // 总成本

    // 计算每种商品的最大购买量
    for (int i = 0; i < N; ++i) {
        long long p = P[i];
        long long k = static_cast<long long>(sqrt(M / p));  // 最大购买量
        long long cost = k * k * p;                         // 购买 k 单位的总成本
        total_units += k;
        total_cost += cost;
    }

    // 如果总成本不超过预算，直接返回总购买量
    if (total_cost <= M) {
        return total_units;
    } else {
        // 需要减少某些商品的购买量
        // 按照 P_i 从大到小的顺序减少购买量
        sort(P.rbegin(), P.rend());  // 将 P 从大到小排序
        for (long long p : P) {
            long long k = static_cast<long long>(sqrt(M / p));
            long long cost = k * k * p;
            if (total_cost - cost <= M) {
                total_units -= k;
                total_cost -= cost;
            } else {
                // 减少部分购买量
                long long new_k = static_cast<long long>(sqrt((M - (total_cost - cost)) / p));
                total_units -= (k - new_k);
                total_cost -= (cost - new_k * new_k * p);
                break;
            }
        }
        return total_units;
    }
}

int main() {
    // 输入
    int N;
    long long M;
    cin >> N >> M;
    vector<long long> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    // 计算最大购买量
    long long result = max_units(N, M, P);

    // 输出
    cout << result << endl;

    return 0;
}