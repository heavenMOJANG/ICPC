#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,m,a[10010],g[110][110],ans;
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    static ll sta[35];
    ll top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
class Solution{
public:
    void main(){
        read(n);read(m);
        for(ll i=1;i<=m;++i) read(a[i]);
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) read(g[i][j]);
        for(ll k=1;k<=n;++k)
            for(ll i=1;i<=n;++i)
                for(ll j=1;j<=n;++j) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
        for(ll i=2;i<=m;++i) ans+=g[a[i-1]][a[i]];
        write(ans);
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    _=1;
    while(_--){
        solution.main();
    }
    return 0;
}
