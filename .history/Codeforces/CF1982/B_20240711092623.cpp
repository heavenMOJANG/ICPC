#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void solve(){
    int x,y,k;cin>>x>>y>>k;
    int a=y-(x%y);
    while(k){
        if(k>=a) k-=a;
        else {x+=k,k=0;break;}
        x+=a;
        while(x%y==0){
            x/=y;
            if(x==1){
                x+=(k%(y-1));
                while(x%y==0) x/=y;
                k=0;
            }
        }
        a=y-(x%y);
    }
    cout<<x<<"\n";
    return;
}
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int _=1;//cin>>_;
    while(_--) solve();
    return 0;
}