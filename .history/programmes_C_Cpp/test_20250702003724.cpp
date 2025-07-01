#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

    // 预处理 spf（smallest prime factor）
    vector<int> spf(Nmax+1, 0);
    for(int i = 2; i <= Nmax; i++){
        if(spf[i] == 0){
            // i 是素数
            for(int j = i; j <= Nmax; j += i){
                if(spf[j] == 0) spf[j] = i;
            }
        }
    }

    // 对每个测试
    for(int _ = 0; _ < T; _++){
        int n = Ns[_];
        vector<int> p(n+1, 0);

        // 分组：对于 i>=2 且 spf[i] <= n/2，加入组 spf[i]
        vector<vector<int>> grp(n+1);
        for(int i = 2; i <= n; i++){
            if(spf[i] <= n/2){
                grp[spf[i]].push_back(i);
            }
        }

        // 对每个质因子 p <= n/2，有 grp[p].size() >= 2
        // 在各自组内做一次循环移位
        for(int pr = 2; pr <= n/2; pr++){
            auto &C = grp[pr];
            int m = C.size();
            if(m == 0) continue;
            for(int j = 0; j < m; j++){
                int i_cur = C[j];
                int i_nxt = C[(j+1)%m];
                p[i_cur] = i_nxt;
            }
        }

        // 剩下的位置：i=1 或 素数 p>n/2，一律固定
        p[1] = 1;
        for(int i = 2; i <= n; i++){
            if(p[i] == 0){
                p[i] = i;
            }
        }

        // 输出
        for(int i = 1; i <= n; i++){
            cout << p[i] << (i==n?'\n':' ');
        }
    }

    return 0;
}
