#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
vector<int> getNext(string s) {
    int n = s.length();
    vector<int> next(n, 0);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && s[i] != s[j]) j = next[j - 1];
        if (s[i] == s[j]) j++;
        next[i] = j;
    }
    return next;
}

int shortestRepetition(string s) {
    int n = s.length();
    string t = s + s;
    vector<int> next = getNext(t);
    int idx = next.back();
    return (idx + n < t.length()) ? n - idx : n;
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
