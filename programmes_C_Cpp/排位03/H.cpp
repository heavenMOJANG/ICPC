#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
void write(__int128 n){
    if(n<0){putchar('-');n*=-1;}
    static int sta[256];
    int top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
void solve(){
    int n;
    while(cin>>n){
        if(n<3) return;
        __int128 x=n;
        __int128 ans=4*x*x*x-18*x*x+20*x-3*(1-(x&1?-1:1));
        ans/=48;
        write(ans);
        puts("");
    }
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;
    while(_--) solve();
    return 0;
}
