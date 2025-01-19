#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
constexpr int inf=0x7fffffff;
int idx;
void solve(){
    double t1,t2,s1,s2,w;cin>>t1>>t2>>s1>>s2>>w;
    function<double(double)> cal=[&](double d)->double
    {
        double s=(t2-t1)*(s2-s1);
        if(t2+d<s1) return 0.0;
        if(t1+d<=s1){
            if(t2+d<=s2)
                return (t2-s1+d)*(t2-s1+d)*0.5;
            else
                return((t2-s2+d)+(t2-s1+d))*(s2-s1)*0.5;
        }
        if(t1+d<s2){
            if(t2+d<=s2)
                return ((t1-s1+d)+(t2-s1+d))*(t2-t1)*0.5;
            else
                return s-((s2-t1-d)*(s2-t1-d))*0.5;
        }
        else return s;
    };
    double p=cal(w)-cal(-w);
    p/=(t2-t1)*(s2-s1);
    cout<<"Case #"<<++idx<<": "<<fixed<<setprecision(8)<<p<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
