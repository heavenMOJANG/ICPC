#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q; cin >> q;
    int balance = 0; // Tracks net balance: +1 for '(', -1 for ')'
    vector<char> seq; // To track last character
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            char c; cin >> c;
            seq.push_back(c);
            balance += (c == '(' ? 1 : -1);
        } else {
            balance += (seq.back() == '(' ? -1 : 1);
            seq.pop_back();
        }
        cout << (balance == 0 ? "Yes\n" : "No\n");
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}