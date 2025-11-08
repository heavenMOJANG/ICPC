#include <bits/stdc++.h>
using namespace std;

void solve() {
    int q; cin >> q;
    int balance = 0; // +1 for '(', -1 for ')'
    bool valid = true; // Tracks if sequence has invalid prefix
    vector<char> s; // To track last character
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            char c; cin >> c;
            s.push_back(c);
            balance += (c == '(' ? 1 : -1);
            if (balance < 0) valid = false; // Invalid prefix
        } else {
            char lst = s.back(); s.pop_back();
            balance += (lst == '(' ? -1 : 1);
            // If removing a ')', check if balance becomes non-negative
            if (lst == ')' && balance >= 0 && !s.empty()) valid = false;
        }
        cout << (balance == 0 && valid ? "Yes\n" : "No\n");
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}