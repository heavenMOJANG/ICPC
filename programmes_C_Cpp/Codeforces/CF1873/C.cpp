#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
void solve(){
    ll cnt=0;
    char ch;
    for(ll i=1;i<=10;++i)
        for(ll j=1;j<=10;++j){
            cin>>ch;
            if(ch=='X'){
                if(i==1||i==10||j==1||j==10) cnt+=1;
                if(((i==2||i==9)&&(1<j&&j<10))||((j==2||j==9)&&(2<i&&i<10))) cnt+=2;
                if(((i==3||i==8)&&(2<j&&j<9))||((j==3||j==8)&&(2<i&&i<9))) cnt+=3;
                if(((i==4||i==7)&&(3<j&&j<8))||((j==4||j==7)&&(3<i&&i<8))) cnt+=4;
                if(((i==5||i==6)&&(4<j&&j<7))||((j==5||j==6)&&(4<i&&i<7))) cnt+=5;
            }
        }
    cout<<cnt<<"\n";
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;cin>>_;
    while(_--) solve();
    return 0;
}
