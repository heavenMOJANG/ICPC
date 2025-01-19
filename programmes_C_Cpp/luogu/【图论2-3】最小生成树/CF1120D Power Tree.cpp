#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define findc(x) (lower_bound(c.begin(),c.end(),x)-c.begin()+1)
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
struct Edge{ll to,nxt;}e[4000010];
ll n,w[2000010],head[2000010],idx,id[2000010],cnt,con[2000010],b[2000010],f[2000010],res;
vector<ll>c,ans;
void addEdge(ll u,ll v){e[++idx]={v,head[u]},head[u]=idx;}
void dfs(ll u,ll fa){
	id[u]=++cnt;
	for(ll i=head[u];i;i=e[i].nxt) if(e[i].to!=fa) dfs(e[i].to,u);
	con[u]=cnt;
	if(id[u]==con[u]) c.push_back(id[u]);
}
ll findSet(ll x){return f[x]==x?x:findSet(f[x]);}
ll cmp(ll x,ll y){return w[x]<w[y];}
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    read(n);
    for(ll i=1;i<=n;++i) read(w[i]),b[i]=i;
    for(ll i=1,u,v;i<n;++i) read(u),read(v),addEdge(u,v),addEdge(v,u);
    dfs(1,0);
    sort(b+1,b+1+n,cmp);
    sort(c.begin(),c.end());
	for(ll i=1;i<=n+1;++i) f[i]=i;
    for(ll i=1;i<=n;++i){
		ll j=i;
        while(j<n&&w[b[j+1]]==w[b[i]])j++;
		for(ll k=i;k<=j;++k){
			ll x=findc(id[b[k]]),y=findc(con[b[k]]+1);
			x=findSet(x),y=findSet(y);
			if(x!=y) ans.push_back(b[k]);
		}
		for(ll k=i;k<=j;++k){
			ll x=findc(id[b[k]]),y=findc(con[b[k]]+1);
			x=findSet(x),y=findSet(y);
			if(x!=y) f[y]=x,res+=w[b[k]];
		}
		i=j;
	}
    sort(ans.begin(),ans.end());
    write(res);putchar(' ');write(ans.size());puts("");
    for(auto i:ans) write(i),putchar(' ');puts("");
    return 0;
}
