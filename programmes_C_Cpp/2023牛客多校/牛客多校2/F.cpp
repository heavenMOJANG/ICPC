#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
ll _,n,r,g,b,ans[8];
void read(ll&n){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    n=x*f;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read(_);
    while(_--){
        read(n);read(r);read(g);read(b);
        ans[0]=(r-1)+(g-1)+(b-1);
        ans[1]=(r-1)+(g-1)+(n-b);
        ans[2]=(r-1)+(n-g)+(b-1);
        ans[3]=(r-1)+(n-g)+(n-b);
        ans[4]=(n-r)+(g-1)+(b-1);
        ans[5]=(n-r)+(g-1)+(n-b);
        ans[6]=(n-r)+(n-g)+(b-1);
        ans[7]=(n-r)+(n-g)+(n-b);
        ll flag=0;
        for(ll i=0;i<8;++i) if(ans[i]&1) flag=1;
        puts(flag?"Alice":"Bob");
    }
    return 0;
}
