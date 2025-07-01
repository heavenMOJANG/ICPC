#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x7fffffff;
ll _,n,m,dis[510][510],g[510][510];
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
        read(n);read(m);
        for(ll i=1;i<=n;++i)
            for(ll j=1;j<=n;++j) g[i][j]=dis[i][j]=inf;
        for(ll i=1,u,v,w;i<=m;++i)
            read(u),read(v),read(w),g[u][v]=dis[u][v]=w;
        ll minn=inf,cnt=0;
        for(ll k=1;k<=n;++k){
            for(ll i=1;i<k;++i) 
                for(ll j=i+1;j<k;++j) 
                {
                    ll tmp=dis[i][j]+g[j][k]+g[k][i];
                  //  cout<<tmp<<endl;
                    if(tmp<minn) minn=tmp,cnt=1;
                    else if(tmp==minn) cnt++;
                }
            for(ll i=1;i<=n;++i)
                for(ll j=1;j<=n;++j)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    
        }
        if(cnt>0) write(minn),putchar(' '),write(cnt*2),puts("");
        else puts("-1 -1");
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
