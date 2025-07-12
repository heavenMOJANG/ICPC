#include <iostream>
#include <vector>
using namespace std;

bool is_palindrome(const vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n / 2; ++i) {
        if (a[i] != a[n - 1 - i]) return false;
    }
    return true;
}

string solve_one_case(int n, int k, const vector<int>& a) {
    if (k == 1 || is_palindrome(a)) {
        return "YES";
    }

    if (a[0] != a[n - 1]) {
        return "NO";
    }

    int lcnt = 0;
    while (lcnt < n && a[lcnt] == a[0]) {
        lcnt++;
    }

    int rcnt = 0;
    while (rcnt < n && a[n - 1 - rcnt] == a[0]) {
        rcnt++;
    }

    if (lcnt >= k || rcnt >= k || (lcnt + rcnt >= k)) {
        return "YES";
    }
    return "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << solve_one_case(n, k, a) << '\n';
    }
    return 0;
}
