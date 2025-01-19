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
ll _,n,k,a[200010];
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read(_);
    while(_--){
        read(n);read(k);
        for(ll i=1;i<=n;++i) read(a[i]);
        if(a[1]!=1){puts("1");continue;}
        a[n+1]=1e18;
        vector<ll>ans;
        ll cnt=1,d=1;
        for(ll i=2;i<=n+1;++i){
            while(cnt+d<a[i]){
                cnt+=d;
                ans.push_back(cnt);
                if(ans.size()>k+1) break;
            }
            if(ans.size()>k+1) break;
            d=i;
        }
        write(ans[k-1]);puts("");
    }
    return 0;
}
