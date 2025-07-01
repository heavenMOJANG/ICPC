#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 2e6 + 10;
class Trie {
public:
    struct Node {
        int ch[26];
        bool f;
        unordered_set<int> Z;
        Node () {
            for (int i{}; i < 26; ++ i) ch[i] = -1;
            f = 0;
        }
    };
    vector<Node> nodes;
    unordered_set<int> Z;
    Trie () { nodes.emplace_back(); }
    void add(const string& s, int i, bool isY) {
        int k{};
        for (char ch : s) {
            int c = ch - 'a';
            if (isY) {
                nodes[k].Z.insert(i);
                if (nodes[k].f) Z.insert(i);
            }
            if (nodes[k].ch[c] == -1) {
                nodes[k].ch[c] = nodes.size();
                nodes.emplace_back();
            }
            k = nodes[k].ch[c];
        }
        if (isY) {
            nodes[k].Z.insert(i);
            if (nodes[k].f) Z.insert(i);
        } else {
            nodes[k].f = 1;
            for (auto x : nodes[k].Z) Z.insert(x);
            nodes[k].Z.clear();
        }
    }
};
void solve() {
    int q; cin >> q;
    Trie trie;
    int Y{};
    for (int i{}; i < q; ++ i) {
        string t, s; cin >> t >> s;
        trie.add(s, i, t == "2");
        if (t == "2") Y ++;
        cout << Y - trie.Z.size() << "\n";
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}