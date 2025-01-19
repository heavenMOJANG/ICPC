#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int shortestRepetition(string s) {
    int n = s.length();
    int ans = n;
    for (int k = 1; k <= n; k++) {
        if (n % k == 0) {
            unordered_map<string, int> freq;
            int maxCnt = 0;
            string t;
            for (int i = 0; i < n; i += k) {
                string sub = s.substr(i, k);
                freq[sub]++;
                if (freq[sub] > maxCnt) {
                    maxCnt = freq[sub];
                    t = sub;
                }
            }
            int cnt = maxCnt;
            int diff = 0;
            for (int i = 0; i < n; i += k) {
                string sub = s.substr(i, k);
                if (sub != t) {
                    diff++;
                }
            }
            if (diff <= 1 && cnt * k == n) {
                ans = min(ans, (int)t.length());
            }
        }
    }
    return ans;
}
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    cout<<shortestRepetition(s)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
