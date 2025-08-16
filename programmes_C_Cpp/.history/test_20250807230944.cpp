#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--){
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        // 如果一开始就在任意一侧边界，第一天建墙后即可立刻逃跑
        if (x == 1 || x == n) {
            cout << 1 << "\n";
            continue;
        }
        // 统计左侧区间 [1, x-1] 的总格数 SL，已有墙 WL，空格 EL
        int SL = x - 1;
        int WL = 0;
        for (int i = 0; i < x - 1; i++){
            if (s[i] == '#') WL++;
        }
        int EL = SL - WL;
        // 同理右侧区间 [x+1, n]
        int SR = n - x;
        int WR = 0;
        for (int i = x; i < n; i++){
            if (s[i] == '#') WR++;
        }
        int ER = SR - WR;

        // 计算左右两侧各自“最差情况下”Hamid逃跑需要的天数
        auto need = [&](int W, int E){
            if (W == 0) return 1;        // 那侧初始就无墙
            return W + E + 1;            // 先要破 W 扇已有的，再应对 Mani 最多 E 天的添墙，最后一天逃跑
        };
        int TL = need(WL, EL);
        int TR = need(WR, ER);

        // Mani 每天先下手，却不知道Hamid往哪边跑，因此要看两边都跑得慢的那一边
        int ans = max(TL, TR);
        cout << ans << "\n";
    }

    return 0;
}
