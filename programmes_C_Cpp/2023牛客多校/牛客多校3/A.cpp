#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    if(n>9) write(n/10);
    putchar(n%10+'0');
}
string s,t;
ll x,y;
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s>>t;
    for(ll i=0;i<s.size();++i) x+=pow(2,s.size()-i-1)*(s[i]-48);
    for(ll i=0;i<t.size();++i) y+=pow(2,t.size()-i-1)*(t[i]-48);
    if(x==y) return puts("0"),0;
    if(x!=y){
        if(x==0) write(-1),puts("");
        else write(abs(x-y)),puts("");
    }
    return 0;
}
