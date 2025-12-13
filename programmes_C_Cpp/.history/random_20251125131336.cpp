#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MOD = 5e5;
mt19937_64 rnd(time(0));
void makeTestcase(int idx) {
    string outf = to_string(idx) + ".in";
    freopen(outf.c_str(), "w", stdout);
    vector<string> testcases;
    int tokens = MOD;
    while (tokens) {
        int n = rnd() % (MOD - 1) + 1;
        n = min(n, tokens);
        string testcase{};
        for (int i{}; i < n; ++ i) testcase.push_back(rnd() & 1 ? '1' : '0');
        testcases.push_back(testcase);
        tokens -= n;
    }
    cout << testcases.size() << "\n";
    for (auto &s : testcases) {
        cout << s.size() << "\n" << s << "\n";
    }
    fclose(stdout);
    return;
}
signed main(){
    for (int i = 1; i <= 10; ++ i) makeTestcase(i);
    return 0;
}
