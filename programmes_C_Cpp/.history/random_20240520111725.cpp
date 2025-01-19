#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define random(a,b) (rand()%(b-a+1))+a
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mod=1e9;
int solve(){
    return (rand())%1000;
}
signed main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    freopen("8.in","w",stdout);
    srand(time(NULL));
    int _=100000;
    cout<<"100000\n";
    vector<int>a;
    for(int i=0;i<_;++i) a.emplace_back(solve());
    for(int i=0;i<a.size();++i) cout<<a[i]<<" \n"[i==a.size()-1];
    return 0;
}
