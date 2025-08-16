#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 计算 S(m) = 2^{floor(log2(m))+1} - 1
// 即最高的 2^k <= m，则 S(m) = 2^{k+1}-1
ll S(ll m) {
    // 找到最高位 1 所在的位置
    // __lg(m) == floor(log2(m))
    int k = __lg(m);
    return ((1LL << (k+1)) - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<ll> b(n);
        for(int i=0; i<n; i++){
            cin >> b[i];
        }

        bool ok = true;
        // 前缀最小值初始化为 b[0]
        ll m = b[0];
        // 从 i=1 对应题目里的 i=2 开始检查
        for(int i=1; i<n; i++){
            // 若 b[i] 超过 S(m)，则不可能凑出
            if(b[i] > S(m)){
                ok = false;
                break;
            }
            // 更新前缀最小
            m = min(m, b[i]);
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
