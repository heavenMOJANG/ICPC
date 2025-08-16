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
        // 0-based 转换
        int pos = x - 1;

        // 统计左侧 [0, pos-1] 墙与空格
        int WL0 = 0;
        for (int i = 0; i < pos; i++)
            if (s[i] == '#') WL0++;
        int EL = pos - WL0;

        // 统计右侧 [pos+1, n-1]
        int WR0 = 0;
        for (int i = pos + 1; i < n; i++)
            if (s[i] == '#') WR0++;
        int ER = (n - 1 - pos) - WR0;

        // 如果任一侧初始就没墙，第一天建完就能跑
        if (WL0 == 0 || WR0 == 0) {
            cout << 1 << "\n";
            continue;
        }

        // 计算两种“全力拖延”方案的天数
        int A = max(WL0 + EL, WR0) + 1;
        int B = max(WR0 + ER, WL0) + 1;
        int ans = min(A, B);

        cout << ans << "\n";
    }
    return 0;
}
