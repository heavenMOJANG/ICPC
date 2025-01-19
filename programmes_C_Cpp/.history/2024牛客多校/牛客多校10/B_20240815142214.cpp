#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e5 + 10;
struct Node {
    string val;
    int id, lson, rson;
};
void solve() {
    int n, q; cin >> n >> q;
    vector<string> typeName(n), variableName(n);
    vector<Node> tree(N << 2);
    vector<int> rt(n);
    int idx = 0, p = 0;
    function<void(int, string)> build = [&](int u, string str) {
        tree[u].id = idx;
        tree[u].val = str;
        if (str[0] == 'p') {
            str = str.substr(5, str.size() - 1);
            switch (str[0]) {
                case 'i':{
                    string ls = str.substr(0, 3), rs = str.substr(4,str.size());
                    build(tree[u].lson = ++ idx, ls);
                    build(tree[u].rson = ++ idx, rs);
                    break;
                }
                case 'd':{
                    string ls = str.substr(0, 6), rs = str.substr(7,str.size());
                    build(tree[u].lson = ++ idx, ls);
                    build(tree[u].rson = ++ idx, rs);
                    break;
                }
                default:{
                    int cnt = 0, p;
                    for (int i = 4; i < str.size(); ++ i) {
                        if (str[i] == '<') cnt++;
                        if (str[i] == '>') cnt--;
                        if (!cnt) {p = i; break;}
                    }
                    string ls = str.substr(0, p + 1), rs = str.substr(p + 2, str.size());
                    build(tree[u].lson = ++ idx, ls);
                    build(tree[u].rson = ++ idx, rs);
                    break;
                }
            }
        }
        return ;
    };
    for (int i = 0; i < n; ++ i) {
        cin >> typeName[i] >> variableName[i];
        variableName[i].pop_back();
        build(rt[i] = ++idx, typeName[i]);
    }
    function<void(int, string)> dfs = [&](int u, string str) {
        if (str.size() == 0) {
            cout << tree[u].val << "\n";
            return;
        }
        char op = str.front(); str.erase(0);
        if (op == '0') dfs(tree[u].lson, str);
        else dfs(tree[u].rson, str);
    };
    while (q --) {
        string s; cin >> s;
        string str;
        dfs(rt[i], str);
    }
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}