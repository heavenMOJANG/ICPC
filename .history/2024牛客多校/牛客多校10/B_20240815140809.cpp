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
    function<int(int,string)> build = [&](int u, string str) {
        tree[u].id = idx;
        tree[u].val = str;
        if (str[0] == 'p') {
            str = str.substr(5, str.size() - 1);
            switch (str[0]) {
                case 'i':
                    string ls = str.substr(0,3), rs = str.substr(4,str.size());
                    tree[u]
            }
        }
        return tree[u].id;
    };
    for (int i = 0; i < n; ++ i) {
        cin >> typeName[i] >> variableName[i];
        variableName[i].pop_back();
        rt[i] = idx++;
        build(idx, typeName);
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