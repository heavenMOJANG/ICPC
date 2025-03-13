#include <bits/stdc++.h>
using namespace std;
struct Node {
    int opt;
    string s0, s1;
    Node(int o, string s, string t) : opt(o), s0(s), s1(t) {}
};
std::string subreplace(std::string resource_str, std::string sub_str, std::string new_str)
{
    std::string dst_str = resource_str;
    std::string::size_type pos = 0;
    while((pos = dst_str.find(sub_str)) != std::string::npos)
    {
        dst_str.replace(pos, sub_str.length(), new_str);
    }
    return dst_str;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n; cin >> n;
    vector<Node> a;
    for (int i = 0; i < n; ++ i) {
        int opt; cin >> opt;
        string pre, suf = "";
        if (opt == 1) {
            cin >> pre;
            a.push_back(Node(opt, pre, suf));
        } else {
            cin >> pre >> suf;
            a.push_back(Node(opt, pre, suf));
        }
    }
    cin.ignore();
    string txt;
    getline(cin, txt);
    for (int i = 0; i < n; ++ i) {
        if (a[i].opt != 3) {
            txt = subreplace(txt, a[i].s0, a[i].s1);
        } else txt = a[i].s0 + txt + a[i].s1;
    }
    cout << txt << "\n";
    return 0;
}