#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
int shortestRepetition(string s) {
    int n = s.length();
    vector<int> pi(n + 1);
    pi[0] = -1;
    int j = -1;
    for (int i = 0; i < n; i++) {
        while (j >= 0 && s[i] != s[j]) {
            j = pi[j];
        }
        j++;
        pi[i + 1] = j;
    }

    int ans = n;
    for (int i = n; i >= 1; i--) {
        if (n % i == 0 && pi[i] == 0) {
            int x = n / i;
            string t = s.substr(0, i);
            int diff = 0;
            for (int j = 0; j < n; j += i) {
                if (s.substr(j, i) != t) {
                    diff++;
                }
            }
            if (diff <= 1) {
                ans = min(ans, i);
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
