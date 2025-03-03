#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
constexpr int MOD = 1e5;
constexpr int MAX = 1e5;
mt19937 rnd(time(0));
signed main(){
    cout.tie() -> sync_with_stdio(0);
    freopen("1.in", "w", stdout);
    cout << MOD << endl;
    for (int i = 1; i <= MOD; ++ i) {
        cout << rnd() % (MAX + 1);
        if (i == MOD) cout << endl;
        else cout << " ";
    }
    for (int i = 1; i < MOD; ++ i) {
        cout << "1 " << i + 1 << endl;
    }
    fclose(stdout);
    int flag{};
    freopen("1.in", "r", stdin);
    int n; cin >> n;
    for (int i = 1; i <= n; ++ i) {
        int x; cin >> x;
        if (x > MAX) flag = 1;
    }
    fclose(stdin);
    cout << flag << "\n";
    return 0;
}
