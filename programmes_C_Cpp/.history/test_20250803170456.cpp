#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> A(n+1);
    for(int i = 1; i <= n; i++){
        cin >> A[i];
    }

    // 预处理 f[k][i] = Δ^{2^k}A[i] = A[i] ⊕ A[i + 2^k]
    int K = 1 + __lg(n);
    vector<vector<int>> f(K, vector<int>(n+2, 0));
    for(int k = 0; k < K; k++){
        int span = 1 << k;
        for(int i = 1; i + span <= n; i++){
            f[k][i] = A[i] ^ A[i + span];
        }
    }

    // 处理每个查询
    while(q--){
        int l, r;
        cin >> l >> r;
        int m = r - l;
        if(m == 0){
            // 区间长度 1，直接返回 A[l]
            cout << A[l] << "\n";
            continue;
        }
        int ans = A[l];   // 初始答案
        int off = 0;      // 当前偏移
        // 递归分治剥高位，等价于二进制拆分
        while(m){
            int k = 31 - __builtin_clz(m);  // 找最高位 2^k
            int bit = 1 << k;
            // 用一次 2^k 次差分，从位置 l+off 取值
            ans ^= f[k][l + off];
            off += bit;
            m -= bit;
        }
        cout << ans << "\n";
    }

    return 0;
}
