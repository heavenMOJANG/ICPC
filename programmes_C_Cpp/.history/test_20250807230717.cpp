#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        // Convert to 0-based index
        int pos = x - 1;

        // Find nearest wall to the left
        int dL = INT_MAX;
        for (int i = pos - 1; i >= 0; --i) {
            if (s[i] == '#') {
                dL = pos - i - 1;
                break;
            }
        }

        // Find nearest wall to the right
        int dR = INT_MAX;
        for (int i = pos + 1; i < n; ++i) {
            if (s[i] == '#') {
                dR = i - pos - 1;
                break;
            }
        }

        // If one side is already open, Hamid escapes in 1 day
        if (dL == INT_MAX || dR == INT_MAX) {
            cout << 1 << "\n";
        } else {
            int a = min(dL, dR);
            int b = max(dL, dR);
            // Optimal play duration
            int days = max(2 * a + 1, b + 1);
            cout << days << "\n";
        }
    }

    return 0;
}
