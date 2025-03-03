#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 0x7fffffff;
void solve() {
    string s; getline(cin, s);
    int tmp{};
    stack<int> st;
    for (int i = 0; i < (int)s.size(); ++ i) {
        if (s[i] == '#') {
            st.push(tmp);
            tmp = 0;
        } else if ('0' <= s[i] && s[i] <= '9') {
            tmp = tmp * 10 + s[i] - '0';
        } else {
            int y = st.top(); st.pop();
            int x = st.top(); st.pop();
            switch (s[i]) {
                case '+':
                    st.push(x + y);
                    break;
                case '-':
                    st.push(x - y);
                    break;
                case '*':
                    st.push(x * y);
                    break;
                case '/':    
                    st.push(x / y);
                    break;
            }
        }
    }
    cout << st.top() << '\n';
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}