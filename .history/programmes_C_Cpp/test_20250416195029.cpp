#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 0x7fffffff;
constexpr int N = 1000;
bool sex[N];
double g[N][N];
int row[500];
void solve() {
    int n, m; cin >> n >> m;
    for (int i{}; i < m; ++ i) {
        int k; cin >> k;
        for (int j{}; j < k; ++ j) {
            string s; cin >> s;
            if (s[0] == '-') {
                int x = abs(stoi(s));
                sex[x] = 0;
                row[j] = x;
            } else {
                int x = stoi(s);
                sex[x] = 1;
                row[j] = x;
            }
        }
        for (int a{}; a < k - 1; ++ a)
            for (int b = a + 1; b < k; ++ b) {
                if (sex[row[a]] != sex[row[b]]) g[row[a]][row[b]] += 1.0 / k, g[row[b]][row[a]] += 1.0 / k;
            }
    }
    int A, B; cin >> A >> B; A = abs(A), B = abs(B);
    double maxA{}, maxB{};
    for (int i{}; i < n; ++ i) if (sex[i] != sex[A]) maxA = max(maxA, g[i][A]);
    for (int i{}; i < n; ++ i) if (sex[i] != sex[B]) maxB = max(maxB, g[i][B]);
    function<void(int)> print = [&](int x) {
        if (!sex[x]) cout << "-";
        cout << x;
    };
    if (g[A][B] == maxA && g[A][B] == maxB) {
        print(A); cout << " ";
        print(B); cout << "\n";
    } else {
        for (int i{}; i < n; ++ i)
            if (sex[i] != sex[A] && g[i][A] == maxA) {
                print(A); cout << " ";
                print(i); cout << "\n";
            }
        for (int i{}; i < n; ++ i)
            if (sex[i] != sex[B] && g[i][B] == maxB) {
                print(B); cout << " ";
                print(i); cout << "\n";
            }
    }
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; //cin >> _;
    while(_ --) solve();
    return 0;
}