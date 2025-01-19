#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m;
char g[1010][1010],op[2]={'x','o'};
void readln(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
int main(int argc,const char**argv){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    readln(T);
    while(T--){
        map<char,ll>mp;
        readln(n);readln(m);
        for(ll i=0;i<n-1;++i){
            ll f=i&1;
            for(ll j=0;j<m;++j){
                if(j%4==0) f=1-f;
                putchar(op[f]),mp[op[f]]++;
            }
            putchar('\n');
        }
        if(mp['o']-mp['x']>1){
            ll f=(n-1)&1;
            for(ll j=0;j<m;++j){
                if(j%4==0) f=1-f;
                putchar(op[f]),mp[op[f]]++;
            }
        }
        else for(ll j=0;j<m;++j) putchar(op[j&1]);
        putchar('\n');
    }
    return 0;
}