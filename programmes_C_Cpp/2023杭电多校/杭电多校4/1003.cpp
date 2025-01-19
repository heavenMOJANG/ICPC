#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll inf=0x3f3f3f3f;
ll cnt,po,st[4000010],a[4000010],idx,b[4000010];
std::vector<ll>seg[4000010],id[4000010];
ll _,k;
char buf[1<<23],*p1=buf,*p2=buf,obuf[1<<23],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	return x*f;
}
void write(ll x) {
    if(x>9) write(x/10);
    *O++=x%10+'0';
}
ll find(ll x){
	ll l=1,r=idx;
	while(l<r){
		ll mid=l+r>>1;
		if(a[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}
class Solution{
public:
    void main(){
        k=read();
        idx=0;
        for(ll i=1,x,y;i<=k;++i){
            x=read();
            seg[i].resize(x);st[i]=0;
            for(ll j=0;j<x;++j) seg[i][j]=read(),b[++idx]=seg[i][j];
        }
        sort(b+1,b+1+idx);
        ll idxx=0;
        a[++idxx]=b[1];
        for(ll i=2;i<=idx;++i) if(b[i]!=b[i-1]) a[++idxx]=b[i];
	    idx=idxx;
        for(ll i=1;i<=idx;++i) id[i].clear();
        for(ll i=1;i<=k;++i){
		    ll len=seg[i].size();
		    for(ll j=0;j<len;++j){
			    ll ide=find(seg[i][j]);
			    id[ide].emplace_back(i);
		    }
	    }
	    ll cur=0,l=1,ans=1e10;
        for(ll i=1;i<=idx;++i){
		    for(auto it:id[i]){
			    if(st[it]==0) cur++;
			    st[it]++; 
		    }
		    ll last=l;
		    while(cur==k){
			    for(auto it:id[l]){
				    if(st[it]==1) cur--;
				    st[it]--;
			    }
			    l++;
		    }
		    if(l!=last){
			    l--; 	
		        for(auto it:id[l]){
				    if(st[it]==0) cur++;
				    st[it]++; 
			    }
		    }
		    if(cur==k&&a[i]-a[l]<ans) ans=a[i]-a[l];
	    }
        write(ans);
        puts("");
    }
};
int main(int argc,const char*argv[]){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    Solution solution;
    _=read();
    while(_--){
        solution.main();
    }
    fwrite(obuf,O-obuf,1,stdout);
    return 0;
}
