#include <bits/stdc++.h>
using namespace std;
struct Node {
    int opt;
    string s0, s1;
    Node(int o, string s, string t) : opt(o), s0(s), s1(t) {}
};
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; ++ i) {
        int opt; cin >> opt;
        string s0, s1;
        if (opt == 1) {
            cin >> s0;
            a[i] = Node(opt, s0, "");
        } else {
            cin >> s0 >> s1;
            a[i] = Node(opt, s0, s1);
        }
    }
    string txt;
    getline(cin, txt);
    for (int i = 0; i < n; ++ i) {
        if (a[i].opt == 3) {
            txt = regex_replace(txt, regex(a[i].s0), a[i].s1);
        } else txt = a[i].s0 + txt + a[i].s1;
    }
    cout << txt << "\n";
    return 0;
}