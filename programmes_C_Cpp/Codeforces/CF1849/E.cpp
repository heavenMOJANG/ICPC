#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,p[1000010];
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    static ll sta[128];
    ll top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
class Solution{
public:
    void main(){
        read(n);
        for(ll i=1;i<=n;++i) read(p[i]);
        vector<ll>dp(n+10,1);
        dp[1]=1;
        ll cnt=0;
        for(ll i=2;i<=n;++i){
            if(p[i]>p[i-1]) dp[i]=dp[i-1]+1;
            cnt+=dp[i];
        }
        write(cnt);
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    //read(_);
    _=1;
    while(_--){
        solution.main();
    }
    return 0;
}
