#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    double px,py,ax,ay,bx,by;cin>>px>>py>>ax>>ay>>bx>>by;
	double AP=pow(px-ax,2)+pow(py-ay,2),BP=pow(px-bx,2)+pow(py-by,2);
	double AO=pow(ax,2)+pow(ay,2),BO=pow(bx,2)+pow(by,2);
	double AB=pow(ax-bx,2)+pow(ay-by,2);
	double ans=max(min(AO,BO),min(AP,BP));
	ans=max(ans,AB/4);
	ans=min(ans,max(AO,AP));
	ans=min(ans,max(BO,BP));
	cout<<fixed<<setprecision(10)<<sqrt(ans)<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
