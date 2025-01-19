#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;
    while(cin>>n&&n){
        vector<int>a;
        for(int i=0,x;i<n;++i){
            cin>>x;
            if(x<100) a.push_back(x);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();++i) cout<<a[i]<<" \n"[i==a.size()-1];
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
