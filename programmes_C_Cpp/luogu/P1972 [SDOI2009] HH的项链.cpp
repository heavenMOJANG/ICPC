#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
constexpr ll inf=0x7fffffff;
constexpr ll N=1e6;
struct Node{ll l,r,k;}q[N];
ll n,m,a[N],pos[N],cnt[N],ans[N],res;
void read(ll&n){
    ll x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
    n=x*f;
}
void write(ll n){
    if(n<0){putchar('-');n*=-1;}
    static ll sta[256];
    ll top=0;
    do{
        sta[top++]=n%10,n/=10;
    }while(n);
    while(top) putchar(sta[--top]+48);
}
ll cmp(Node a, Node b){
    if(pos[a.l]!=pos[b.l]) return pos[a.l]<pos[b.l];
    if(pos[a.l]&1) return a.r>b.r;
    return a.r<b.r;
}
void add(ll x){
    cnt[a[x]]++;
    if(cnt[a[x]]==1) res++;
}
void del(ll x){
    cnt[a[x]]--;
    if(cnt[a[x]]==0) res--;
}
void solve(){
    read(n);
    ll block=sqrt(n);
    for(ll i=1;i<=n;++i){
        read(a[i]);
        pos[i]=(i-1)/block+1;
    }
    read(m);
    for(ll i=1;i<=m;++i){
        read(q[i].l);read(q[i].r);
        q[i].k=i;
    }
    sort(q+1,q+1+m,cmp);
    ll l=1,r=0;
    for(ll i=1;i<=m;++i){
        while(l<q[i].l) del(l++);
        while(r>q[i].r) del(r--);
        while(l>q[i].l) add(--l);
        while(r<q[i].r) add(++r);
        ans[q[i].k]=res;
    }
    for(ll i=1;i<=m;++i) write(ans[i]),puts("");
    return;
}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll _=1;
    while(_--) solve();
    return 0;
}
