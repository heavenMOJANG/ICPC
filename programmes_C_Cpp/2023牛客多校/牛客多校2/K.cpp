#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll n,a[1000010],b[1000010],dp[1000010][3];
void read(ll&n){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    if(n>9) write(n/10);
    putchar(n%10+'0');
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read(n);
    for(ll i=1;i<=n;++i) read(a[i]);
    for(ll i=1;i<=n;++i) read(b[i]);
    for(ll i=0;i<=n;++i)
        for(ll j=0;j<3;++j) dp[i][j]=LLONG_MIN;
    dp[0][0]=0;
    for(ll i=1;i<=n;++i)
        if(b[i]){
            dp[i][0]=max(dp[i][0],dp[i-1][0]+a[i-1]);
            dp[i][1]=max({dp[i-1][0]+a[i],dp[i-1][1]+a[i],dp[i-1][2]+a[i]});
            dp[i][2]=max(dp[i][2],dp[i-1][2]+a[i]);
            if(b[i-1]) dp[i][2]=max(dp[i][2],dp[i-1][1]-a[i-1]+a[i]);
        }
        else{
            dp[i][1]=dp[i-1][2]+a[i];
            if(b[i-1]) dp[i][1]=max(dp[i][1],dp[i-1][1]-a[i-1]+a[i]);
            dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-2][2]});
        }
    write(max({dp[n][0],dp[n][1],dp[n][2]}));
    return 0;
}
