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
    double d;
    while(cin>>d){
        int n;cin>>n;
        vector<double>v1(n),v2(n);
        for(int i=0;i<n;++i) cin>>v1[i]>>v2[i];
        double l=0.0,r=d;
        auto check=[&](double r){
            double k=d-r,res=inf;
            double t=r/v1[n-1]+k/v2[n-1];
            for(int i=0;i<n-1;++i){
                double tt=r/v1[i]+k/v2[i];
                res=min(res,tt-t);
            }
            return res;
        };
        while(r-l>eps){
            double mid1=(2*l+r)/3,mid2=(l+2*r)/3;
            if(check(mid1)>check(mid2)) r=mid2;
            else l=mid1;
        }
        double t=check(l);
        if(check(l)<0) cout<<"The cheater cannot win.\n";
        else cout<<"The cheater can win by "
                 <<fixed<<setprecision(0)<<t*3600
                 <<" seconds with r = "<<setprecision(2)<<l
                 <<"km and k = "<<d-l<<"km.\n";
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
