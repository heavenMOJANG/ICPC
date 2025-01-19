#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int dx[]={-1,-1,0,1,1,1,0,-1};
constexpr int dy[]={0,1,1,1,0,-1,-1,-1};
char g[9][9];
int mine[9][9];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    for (int i = 0; i < 9; ++ i)
        for (int j = 0; j < 9; ++ j) cin >> g[i][j];
    for (int i = 0; i < 9; ++ i)
        for (int j = 0; j < 9; ++ j)
            if (g[i][j] == '8') {
                int flag = 1;
                for(int k = 0; k < 8; ++ k){
                    int x = i + dx[k], y = j + dy[k];
                    if (x < 0 || x >= 9 || y < 0 || y >= 9) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) mine[i][j] = 1;
            }
    return 0;
}