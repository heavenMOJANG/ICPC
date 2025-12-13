#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 1e5;
mt19937_64 rnd(time(0));
void makeTestcase(int idx) {
    string outf = to_string(idx) + ".in";
    freopen(outf.c_str(), "w", stdout);
    cout << 100 << "\n";
    for (int i{}; i < 100; ++ i) {
        int n = rnd() % 6 + 10, a = rnd() % 7 + 1, b = rnd() % (MOD + 1);
        int s = rnd() % 1001;
        cout << n << " " << a << " " << b << "\n" << s << "\n";
        vector<int> v;
        for (int i{}; i < s; ++ i) v.emplace_back(rnd() % 300);
        sort(v.begin(), v.end());
        for (auto t : v) {
            char p = rnd() % n + 'A';
            int v = rnd() % 10;
            if (t < 240) cout << t << " " << p << " " << (v == 0 ? "rj" : "ac") << "\n";
            else cout << t << " " << p << " " << "pd" << "\n";
        }
    }
    fclose(stdout);
    return;
}
signed main(){
    for (int i = 1; i <= 10; ++ i) makeTestcase(i);
    return 0;
}
