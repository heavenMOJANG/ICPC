#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
void solve() {
    int n, a, b, s, penalty = 0;
        std::cin >> n >> a >> b >> s;

        std::map<std::string, int> ac, pd1;
        std::vector<std::tuple<std::string, int>> rj;
        for (int i = 0; i < s; i++) {
            int t;
            std::string p, v;
            std::cin >> t >> p >> v;

            if (v == "ac") {
                if (ac.count(p)) {
                    ac[p] = std::min(ac[p], t);
                } else {
                    ac[p] = t;
                }
            } else if (v == "pd" && !ac.count(p)) {
                if (pd1.count(p)) {
                    pd1[p] = std::min(pd1[p], t);
                } else {
                    pd1[p] = t;
                }
            } else {
                rj.push_back({p, t});
            }
        }

        std::map<std::string, int> rj_cnt;
        for (auto [p, t] : rj) {
            if (ac.count(p) && ac[p] > t) {
                rj_cnt[p]++;
            }
            if (!ac.count(p) && pd1.count(p) && pd1[p] > t) {
                rj_cnt[p]++;
            }
        }

        for (auto [p, t] : ac) {
            penalty += t + 20 * rj_cnt[p];
        }
        for (auto &[p, t] : pd1) {
            t += 20 * rj_cnt[p];
        }
        std::vector<std::tuple<int, std::string>> pd2;
        for (auto [p, t] : pd1) {
            pd2.push_back({t, p});
        }
        std::sort(pd2.begin(), pd2.end());

        if (ac.size() > a || ac.size() == a && penalty < b) {
            std::cout << 0 << "\n";
        } else {
            int f = 1, cnt = ac.size();
            for (auto [t, p] : pd2) {
                penalty += t;
                cnt++;
                if (cnt > a || cnt == a && penalty < b) {
                    std::cout << cnt - ac.size() << "\n";
                    f = 0;
                    break;
                }
            }

            if (f) {
                std::cout << -1 << "\n";
            }
        }
    return;
}
void test(int testcase) {
    string inf = to_string(testcase) + ".in";
    string outf = to_string(testcase) + ".out";
    freopen(inf.c_str(), "r", stdin);
    freopen(outf.c_str(), "w", stdout);
    int _ = 1; cin >> _;
    while(_ --) solve();
    fclose(stdin);
    fclose(stdout);
    return;
}
signed main() {
    for (int i = 1; i <= 10; ++ i) test(i);
    return 0;
}