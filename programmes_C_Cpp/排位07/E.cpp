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
    double p,q,r,s,t,u;
    auto f=[&](double x){return p*pow(exp(1),-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*pow(x,2)+u;};
    while(cin>>p>>q>>r>>s>>t>>u){
        if(f(0)<0||f(1)>0){cout<<"No solution\n";continue;}
        double l=0,r=1;
        while(r-l-eps>0){
            double mid=(l+r)/2,res=f(mid);
            if(res>eps) l=mid;
            else r=mid;
        }
        cout<<fixed<<setprecision(4)<<l<<"\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
