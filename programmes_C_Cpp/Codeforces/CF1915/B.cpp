#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int sum=0;
    char ch;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j){
            cin>>ch;
            if(ch!='?') sum+=ch-'A';
        }
    cout<<char('A'+9-sum)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
