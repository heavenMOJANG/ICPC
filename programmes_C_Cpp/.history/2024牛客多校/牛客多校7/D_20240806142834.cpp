#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int INF = 0x7fffffff;
vector<int>b[100007];
void solve() {
    string a;
    cin>>a;
    int k=0,s=0;
    for (int i = 0; i <= 100000; ++ i) b[i].clear();
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='0')
            k++;
        else
            k--;
        s+=b[k].size();
        b[k].push_back(i);
    }
    cout<<s<<endl;
    return;
}
signed main() {
    cin.tie(0) -> sync_with_stdio(0);
    int _ = 1; cin >> _;
    while(_ --) solve();
    return 0;
}