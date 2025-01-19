#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int shortestRepetition(string s) {
    int n = s.length();
    unordered_set<string> prefixes, suffixes;
    for (int i = 0; i < n; i++) {
        prefixes.insert(s.substr(0, i + 1));
        suffixes.insert(s.substr(n - i - 1));
    }
    for (int k = 1; k <= n / 2; k++) {
        if (n % k == 0) {
            int x = n / k;
            bool ok = false;
            for (int i = 0; i < k; i++) {
                string t = s.substr(i, k);
                if (prefixes.count(t) || suffixes.count(t)) {
                    int diff = 0;
                    for (int j = i; j < n; j += k) {
                        if (s.substr(j, k) != t) {
                            diff++;
                        }
                    }
                    if (diff <= 1) {
                        ok = true;
                        break;
                    }
                }
            }
            if (ok) {
                return k;
            }
        }
    }
    return n;
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
