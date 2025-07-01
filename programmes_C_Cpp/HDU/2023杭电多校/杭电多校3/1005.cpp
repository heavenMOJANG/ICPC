#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
const ll mod=1e9+7;
ll _,n,a[3010],b[3010],dp[3010][3010],pre[3010][3010],ans[3010];
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
        ll idx=0;
        unordered_map<ll,ll>mp,cnt,pos;
        read(n);
        for(ll i=1;i<=n;++i){
            read(a[i]);
            if(mp.find(a[i])==mp.end()) b[++idx]=a[i];
            mp[a[i]]=1,cnt[a[i]]++;
        }
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) dp[i][j]=pre[i][j]=0;
        sort(a+1,a+1+n);
        sort(b+1,b+1+idx);
        for(ll i=1;i<=n;++i) pos[a[i]]=i,ans[i]=0;
        ans[1]=idx;
        for(ll i=1;i<=idx;++i) dp[1][i]=1,pre[1][i]=pre[1][i-1]+dp[1][i];
        for(ll i=2;i<=n;++i)
            for(ll j=1;j<=idx;++j){
                pre[i][j]=pre[i][j-1];
                if(pos[b[j]]>i-1) dp[i][j]=dp[i-1][j];
                dp[i][j]=(dp[i][j]+pre[i-1][j-1])%mod;
                ans[i]=(ans[i]+dp[i][j])%mod;
                pre[i][j]=(pre[i][j]+dp[i][j])%mod;
            }
        for(ll i=1;i<=n;++i) write(ans[i]),puts("");
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    read(_);
    while(_--){
        solution.main();
    }
    return 0;
}
