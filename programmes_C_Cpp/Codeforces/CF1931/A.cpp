#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    for(int i=0;i<26;++i)
        for(int j=0;j<26;++j)
            for(int k=0;k<26;++k)
                if(i+j+k==n-3){
                    char a='a'+i,b='a'+j,c='a'+k;
                    cout<<a<<b<<c<<"\n";
                    return;
                }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
