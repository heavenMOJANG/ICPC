#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    vector<int> Ns(T);
    int Nmax = 0;
    for(int i = 0; i < T; i++){
        cin >> Ns[i];
        Nmax = max(Nmax, Ns[i]);
    }

    // 1) 预处理：计算每个 i 的最大素因子 lpf[i]
    vector<int> lpf(Nmax+1, 0);
    for(int p = 2; p <= Nmax; p++){
        if(lpf[p] == 0){
            // p 是素数
            for(int j = p; j <= Nmax; j += p){
                lpf[j] = p;  // 后来的 p 越来越大，最终留下的是最大素因子
            }
        }
    }

    // 对每个测试用例
    for(int _ = 0; _ < T; _++){
        int n = Ns[_];
        vector<int> perm(n+1, 0);

        // 2) 分组：对于 i>=2，若 lpf[i] <= n/2，加入组 G[lpf[i]]
        vector<vector<int>> G(n+1);
        int half = n / 2;
        for(int i = 2; i <= n; i++){
            int p = lpf[i];
            if(p <= half){
                G[p].push_back(i);
            }
        }

        // 对每个 p <= n/2，组内循环右移
        for(int p = 2; p <= half; p++){
            auto &grp = G[p];
            int m = grp.size();
            if(m < 2) continue;  // 理论上 m>=2，总加个保险
            for(int j = 0; j < m; j++){
                int i_cur = grp[j];
                int i_nxt = grp[(j+1) % m];
                perm[i_cur] = i_nxt;
            }
        }

        // 3) 其余位置只能固定
        perm[1] = 1;
        for(int i = 2; i <= n; i++){
            if(perm[i] == 0){
                perm[i] = i;
            }
        }

        // 输出
        for(int i = 1; i <= n; i++){
            cout << perm[i] << (i==n? '\n' : ' ');
        }
    }

    return 0;
}
