#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int n,m,ax,ay,bx,by;cin>>n>>m>>ax>>ay>>bx>>by;
    int len=bx-ax;
    if(len<=0){cout<<"Draw\n";return;} 
    if(len&1){
        if(abs(ay-by)<=1){cout<<"Alice\n";return;}
        int step=(ay>by?ay-1:m-ay);
        cout<<(2*step-1<=len?"Alice\n":"Draw\n");
    }
    else{
        if(ay==by){cout<<"Bob\n";return;}
        int step=(ay>by?m-by:by-1);
        cout<<(2*step<=len?"Bob\n":"Draw\n");
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
