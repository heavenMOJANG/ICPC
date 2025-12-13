#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 2e5;
mt19937_64 rnd(time(0));
signed main(){
    freopen("6.in", "w", stdout);
    int tokens = 200000;
    vector<string> testcases;
    while (tokens) {
        int n = (int)rnd() % (MOD - 1) + 1;
        n = min(n, tokens);
        string testcase{};
        for (int i{}; i < n; ++ i) {
            char c = rnd() % 26 + 'A';
            testcase += c;
        }
        if (!testcase.empty())testcases.emplace_back(testcase);
        tokens -= n;
    }
    cout << testcases.size() << "\n";
    for (auto &s : testcases) cout << s << "\n";
    fclose(stdout);
    return 0;
}
