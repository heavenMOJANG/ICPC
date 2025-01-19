#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf = 0x7fffffff;
void solve() {
    int n; cin >> n;
    priority_queue<int> pq;
    for (int i = 0, x; i < n; ++ i) cin >> x, pq.push(x);
    vector<int> ans;
    int flag = 0;
    for (int i = 30; i >= 0; -- i) {
        if (pq.top() == 0) {
            flag = 1;
            break;
        }
        queue<int> tmp;
        int x = 1ll << i;
        while(!pq.empty())  tmp.push(abs(pq.top() - x)), pq.pop();
        while(!tmp.empty()) pq.push(tmp.front()), tmp.pop();
        ans.emplace_back(x);
    }
    if(pq.top() > 0) {cout << "-1\n"; return;}
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++ i) cout << ans[i] << " ";
    cout << "\n";
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}