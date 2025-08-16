#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int id, m, k, n;
    cin >> id >> m >> k >> n;
    vector<string> ans(m, "0");

    // 对每个 toy set
    for(int si = 0; si < m; si++){
        bool damaged = false;

        // 对该集合内的 k 件玩具
        for(int ti = 0; ti < k; ti++){
            vector<int> a(n*n);
            for(int i = 0; i < n*n; i++){
                cin >> a[i];
            }
            // 计算置换 a 对初始 [1..n^2] 的逆序对数 mod 2
            int inv_parity = 0;
            for(int i = 0; i < n*n; i++){
                for(int j = i+1; j < n*n; j++){
                    if(a[i] > a[j]) inv_parity ^= 1;
                }
            }
            // 如果是奇置换，则几乎可以判定被 Bob 随机重排
            if(inv_parity == 1) {
                damaged = true;
            }
        }

        ans[si] = damaged ? "1" : "0";
    }

    // 输出长度为 m 的 01 字符串
    for(auto &c : ans) cout << c;
    cout << "\n";
    return 0;
}
