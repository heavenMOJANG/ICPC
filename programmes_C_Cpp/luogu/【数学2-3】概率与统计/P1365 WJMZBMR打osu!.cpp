#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    double res=0.0,c=0.0;
    for(int i=0;i<n;++i)
        switch(s[i]){
            case '?':res+=c+0.5,c=(c+1)/2.0;break;
            case 'o':res+=2*c+1,c++;break;
            case 'x':c=0.0;break;
        }
    cout<<fixed<<setprecision(4)<<res<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
