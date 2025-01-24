#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int count_configurations(int n, vector<int>& a) {
    // 只保留前一个状态
    int prevH = 0, prevL = 0;

    // 初始化
    if (a[0] == 0) {
        prevH = 1; // 第一个同学是 H
    }
    prevL = 1; // 第一个同学是 L

    // 动态规划转移
    for (int i = 2; i <= n; i++) {
        int currH = 0, currL = 0;
        // 如果第 i 个同学是 H
        if (a[i - 1] <= i - 1) { // 确保 a[i-1] 不超过左边的人数
            currH = (prevH + prevL) % MOD;
        }
        // 如果第 i 个同学是 L
        currL = prevH % MOD;

        // 更新前一个状态
        prevH = currH;
        prevL = currL;
    }

    // 计算结果
    int result = (prevH + prevL) % MOD;
    return result;
}

int main() {
    int n;
    cout << "Enter the number of classmates (n): ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the statements of each classmate (a_i): ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = count_configurations(n, a);
    cout << "The number of distinct possible game configurations is: " << result << endl;

    return 0;
}