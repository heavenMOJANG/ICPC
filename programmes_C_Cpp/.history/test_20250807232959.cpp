#include <bits/stdc++.h>
using namespace std;

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
        int pos = x - 1;  // 0-base

        // 计算 dL：向左撞到现有墙的空格距离
        int dL = INT_MAX;
        for (int i = pos - 1; i >= 0; --i) {
            if (s[i] == '#') {
                dL = pos - i - 1;
                break;
            }
        }
        // 计算 dR：向右撞到现有墙的空格距离
        int dR = INT_MAX;
        for (int i = pos + 1; i < n; ++i) {
            if (s[i] == '#') {
                dR = i - pos - 1;
                break;
            }
        }
        // 边界空格数
        int bL = pos;
        int bR = n - 1 - pos;

        // 计算两条“纯奔左/纯奔右”策略下的最坏天数
        // （2*d + 1） vs （b + 1），取最大
        auto TL = max( (dL==INT_MAX?INT_MAX:(2*dL + 1)), bL + 1 );
        auto TR = max( (dR==INT_MAX?INT_MAX:(2*dR + 1)), bR + 1 );

        // Hamid 选两者中更快的
        int ans = min(TL, TR);
        cout << ans << "\n";
    }
    return 0;
}
