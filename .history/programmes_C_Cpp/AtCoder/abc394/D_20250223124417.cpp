#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    string s; cin >> s;
    stack<char> st;
    for (auto ch : s)
        if (ch == '(' || ch == '[' || ch == '<') st.push(ch);
        else {
            if (ch == ')') {
                if (st.empty() || st.top() != '(') { cout << "No\n"; return; }
            }
            if (ch == ']') {
                if (st.empty() || st.top() != '[') { cout << "No\n"; return; }
            }
            if (ch == '>') {
                if (st.empty() || st.top() != '<') { cout << "No\n"; return; }
            }
        }
    cout << (st.empty() ? "Yes\n" : "No\n") << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}