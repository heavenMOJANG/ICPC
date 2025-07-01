#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
string ans[] = {
    "111111111",
    "1*1*1*1*1",
    "11*1*1*11",
    "1*1*1*1*1",
    "11*1*1*11",
    "1*1*1*1*1",
    "11*1*1*11",
    "1*1*1*1*1",
    "111111111",
};
void solve() {
    int n, m; cin >> n >> m;
    vector g(n, vector<char> (m));
    vector gg(n, vector<char> (m));
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) g[i][j] = ans[i][j];
    for (int i{}; i < n; ++ i)
        for (int j{}; j < m; ++ j) if (i == 0 || i == n - 1 || j == 0 || j == m - 1) g[i][j] = '1';
    gg = g;
    auto get_res = [&](string s) {
        stack<int> st;
        int cur = 0;         
        char op = '+';         
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                cur = cur * 10 + (c - '0');
            }
            if ((!isdigit(c)) || i == n - 1) {
                if (op == '+') {
                    st.push(cur);
                } else if (op == '*') {
                    int t = st.top(); st.pop();
                    st.push(t * cur);
                }
                op = c;    
                cur = 0;   
            }
        }
        int res = 0;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    };
    auto calc = [&]() {
        int sum = 0;
        string s = "";
        for (int i = 0; i < n; i++) {
            string s = "";
            for(int j = 0;j < m;j++){
                s += g[i][j];
            }
            sum += get_res(s);
        }
        for(int j = 0;j < m;j++){
            string s = "";
            for(int i = 0;i < n;i++){
                s += g[i][j];
            }
            sum += get_res(s);
        }
        return sum;

    };
    int ress = 1e18;
    function<void(int,int)>dfs = [&](int x,int y){
        if(x == n){
            int sum = calc();
            if(ress > sum){
                ress = sum;
                gg = g;
            }
            return;
        }
        int tx = x,ty = y + 1;
        if(ty == m) tx++,ty = 0;
        if(x % 2 == 0 && g[x][y] != '1'){
            int tx = x,ty = y + 1;
            if(ty == m) tx++,ty = 0;
            g[x][y] = '+';
            int res = calc();
            dfs(tx,ty);
            g[x][y] = '*';
        }
        dfs(tx,ty);        
    };
    dfs(0,0);
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cout<<gg[i][j];
        }
        cout<<'\n';
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while (_ --) solve();
    return 0;
}