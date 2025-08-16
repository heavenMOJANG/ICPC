#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int id, m, k, n;
    cin >> id >> m >> k >> n;
    vector<char> ans(m, '0');

    // 对每个 toy set
    for(int si = 0; si < m; si++){
        bool isBob = false;
        // 对该集合内的 k 件玩具
        for(int ti = 0; ti < k; ti++){
            vector<int> a(n * n);
            for(int i = 0; i < n * n; i++){
                cin >> a[i];
            }
            // 计算逆序对数 mod 2
            int inv = 0;
            for(int i = 0; i < n*n; i++){
                for(int j = i+1; j < n*n; j++){
                    if(a[i] > a[j]) inv ^= 1;
                }
            }
            // 若出现奇置换，则极可能是 Bob 重排
            if(inv == 1) {
                isBob = true;
            }
        }
        ans[si] = isBob ? '1' : '0';
    }

    // 输出结果
    for(char c : ans) cout << c;
    cout << "\n";
    return 0;
}
