#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int a,b,c;cin>>a>>b>>c;
    int leaf;
    if(a){
        leaf=a+1;
        if(leaf!=c){cout<<"-1\n";return;}
        else{
            int dep=0,step=1;
            while(1){
                dep++;
                int old=step-1,now=step*2-1;
                step*=2;
                if(now>a){
                    int remain=now-a;
                    step=(a-old)*2+remain;
                    if(a==old&&b==0){cout<<dep-1<<"\n";return;}
                    b-=remain;
                    if(b <= 0){cout<<dep<<"\n";return;}
                    else{cout<<dep+(b+step-1)/step<<"\n";return;}
                }
            }
        }
    }
    else if(b){
        leaf=1;
        if(c!=1){cout<<"-1\n";return;}
        else{cout<<b<<"\n";return;}
    }
    else{
        if(c==1){cout<<"0\n";return;}
        else{cout << "-1\n";return;}
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
