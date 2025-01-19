#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
constexpr double eps=1e-6;
void solve(){
    double n,C,L;
    while(cin>>L>>n>>C&&L*n*C>=0){
        double l=0.0,r=0.5*L,L0=(1+n*C)*L;
        while(r-l>eps){
            double mid=(l+r)/2;
			double R=(L*L/4+mid*mid)/2/mid;
			if(2*R*asin(L/2/R)<L0) l=mid;
			else r=mid;
        }
        cout<<fixed<<setprecision(3)<<l<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
