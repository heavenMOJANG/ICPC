#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
constexpr ll inf=0x7fffffff;
struct Node{ld x1,y1,x2,y2,xm,ym;}c[2];
void solve(){
    cin>>c[1].x1>>c[1].y1>>c[1].x2>>c[1].y2;
    c[1].xm=(c[1].x1+c[1].x2)/2;c[1].ym=(c[1].y1+c[1].y2)/2;
    cin>>c[0].x1>>c[0].y1>>c[0].x2>>c[0].y2;
    c[0].xm=(c[0].x1+c[0].x2)/2;c[0].ym=(c[0].y1+c[0].y2)/2;
    ld r0=sqrt(pow(c[0].x1-c[0].x2,2)+pow(c[0].y1-c[0].y2,2))/2;
    ld res=abs(c[0].xm-c[1].xm)+abs(c[0].ym-c[1].ym)-sqrt(2.0)*r0;
    cout<<fixed<<setprecision(10)<<res<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
