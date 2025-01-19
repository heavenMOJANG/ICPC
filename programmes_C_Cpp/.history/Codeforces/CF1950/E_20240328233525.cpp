#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int shortestRepetition(string s) {
    int n = s.length();
    string t = s + s;
    for (int k = 1; k <= n; k++) {
        if (n % k == 0) {
            int x = n / k;
            bool ok = false;
            for (int i = 0; i < k; i++) {
                string p = t.substr(i, k);
                if (p * x == t.substr(0, n) || p * x == t.substr(n)) {
                    ok = true;
                    break;
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
