#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int inf=0x7fffffff;
constexpr int mon0[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
constexpr int mon1[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int check(int x){return (x%400==0)||(x%4==0&&x%100!=0);}
void solve(){
    int l,r;cin>>l>>r;
    if(r>9999) r=9999;
    int cnt=0;
    for(int i=l;i<=r;++i){
        int ba=i/1000+i/100%10*10;
        int dc=i%10*10+i/10%10;
        if(check(i)){
            if(1<=dc&&dc<=12&&1<=ba&&ba<=mon0[dc]) cnt++;
            if(0<=dc&&dc<=23&&0<=ba&&ba<=59) cnt+=6;
            if(0<=dc&&dc<=59&&0<=ba&&ba<=59) cnt+=10;
        }
        else{
            if(1<=dc&&dc<=12&&1<=ba&&ba<=mon1[dc]) cnt++;
            if(0<=dc&&dc<=23&&0<=ba&&ba<=59) cnt+=6;
            if(0<=dc&&dc<=59&&0<=ba&&ba<=59) cnt+=10;
        }
    }
    cout<<cnt<<"\n";
    return;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int _=1;cin>>_;
    while(_--) solve();
    return 0;
}
