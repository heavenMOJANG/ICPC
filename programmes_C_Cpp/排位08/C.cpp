#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    double a,b,c;
    while(cin>>a>>b>>c){
        double p1=a/(a+b)*b/(a+b-c-1);
        double p2=b/(a+b)*(b-1)/(a+b-c-1);
        cout<<fixed<<setprecision(5)<<p1+p2<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
