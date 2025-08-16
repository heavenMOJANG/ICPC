#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    if (N == 1) {
        // 特殊处理 N=1
        cout << 1 << "\n";
        cout << 1 << "\n";
        return 0;
    }

    // 计算 k = floor(log2 N)
    int k = 0;
    while ((1LL << (k+1)) <= N) ++k;

    int n = k + 2;               // 矩阵大小
    vector<vector<int>> A(n, vector<int>(n, 0));

    // 1) 主对角线全 1
    for(int i = 0; i < n; i++){
        A[i][i] = 1;
    }
    // 2) 超对角线全 1
    for(int i = 0; i + 1 < n; i++){
        A[i][i+1] = 1;
    }
    // 3) 最后一行写入二进制位
    //    如果第 i 位为 1，就在 A[n-1][(n-2)-i] 置 1
    for(int i = 0; i <= k; i++){
        if ( (N >> i) & 1LL ) {
            A[n-1][n-2 - i] = 1;
        }
    }

    // 输出结果
    cout << n << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << A[i][j] << (j+1<n ? ' ' : '\n');
        }
    }
    return 0;
}
