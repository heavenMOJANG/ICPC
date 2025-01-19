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
int mine[9][9], vis[9][9];
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    for (int i = 0; i < 9; ++ i)
        for (int j = 0; j < 9; ++ j) cin >> g[i][j];
    for (int i = 1; i < 8; ++ i)
        for (int j = 1; j < 8; ++ j)
            if (g[i][j] == '8') {
                if (!vis[i][j]) {
                    vis[i][j] = 1;
                    continue;
                }
                int flag = 1;
                for(int k = 0; k < 8; ++ k){
                    int x = i + dx[k], y = j + dy[k];
                    if (g[x][y] == '8' && vis[x][y]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) 
                    vis[i][j] = 1;
            }
    for (int i = 0; i < 9; ++ i) {
        for (int j = 0; j < 9; ++ j) {
            if (vis[i][j]) cout << '8';
            else cout << '*';
        }
        cout << "\n";
    }
    return 0;
}