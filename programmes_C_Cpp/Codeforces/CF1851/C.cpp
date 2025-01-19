#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll _,n,a[1000010],b,m,k,h,dp[1000010];
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
        read(n);read(k);
        map<ll,ll>mp;
	    for(ll i=1;i<=n;++i) read(a[i]),mp[a[i]]++;
        if(k==1||(k==2&&a[1]==a[n])){puts("YES");return;}
	    if(mp[a[1]]<k||mp[a[n]]<k){puts("NO");return;}
	    vector<int>pre(n+1),pre2(n+1);
        pre[1]=1;
	    for(ll i=2;i<=n;++i)
	    if(a[i]==a[1]) pre[i]=pre[i-1]+1;
	    else pre[i]=pre[i-1];
	    pre2[n]=1; 
	    for(ll i=n-1;i>=1;--i)
	    if(a[i]==a[n]) pre2[i]=pre2[i+1]+1;
	    else pre2[i]=pre2[i+1];
        if(pre[n]>=k&&a[n]==a[1]){puts("YES");return;}
	    for(ll i=1;i<n;++i)
		    if(pre[i]>=k&&pre2[i+1]>=k){puts("YES");return;}
        puts("NO");
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
