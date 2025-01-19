#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    string s; cin >> s;
    int cnt = 0;
    string t = "";
    for(int i = 0; i < s.size(); ++ i){
        if (s.substr(i, 1) == "/"){
            if (cnt < 2 || cnt >= 2 && t.find("=") != -1) cout << t + "\n";
            t.clear();
            cnt ++;
        } else if (s.substr(i, 3) == "://"){
            if (cnt < 2 || cnt >= 2 && t.find("=") != -1) cout << t + "\n";
            t.clear();
            i += 3;
            cnt ++;
        } else t += s[i];
    }
    return;
}
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}