#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int shortestRepetition(string s) {
    int n = s.length();
    for (int k = 1; k <= n; k++) {
        if (n % k == 0) {
            bool ok = true;
            vector<string> substrings;
            for (int i = 0; i < n; i += k) {
                substrings.push_back(s.substr(i, k));
            }
            string first = substrings[0];
            int diff = 0;
            for (string sub : substrings) {
                if (sub != first) {
                    diff++;
                }
            }
            if (diff <= 1) {
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
